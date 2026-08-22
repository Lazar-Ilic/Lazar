"""
Nash Equilibrium Heatmap Plotter
Usage: python nash_heatmaps.py [path/to/result.csv]
Defaults to nash_floodfill_result.csv in the current directory.
"""

import sys
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
from matplotlib.ticker import MaxNLocator

# ── Config ────────────────────────────────────────────────────────────────────
CSV_PATH = sys.argv[1] if len(sys.argv) > 1 else "nash_floodfill_result.csv"
MIN_PROB_TO_PLOT = 1e-3   # rows below this prob are shown as "unexplored" grey
H_LABEL_30 = "30-44"      # display label for h=30 (the collapsed bin)

# ── Load ──────────────────────────────────────────────────────────────────────
df = pd.read_csv(CSV_PATH)
df.columns = df.columns.str.strip()

# Keep only rows that were actually evaluated (prob > threshold OR regret is finite)
evaluated = df[df["prob"] > MIN_PROB_TO_PLOT].copy()

# For regret map we want ALL evaluated rows regardless of prob
all_eval = df[df["regret"].notna() & np.isfinite(df["regret"])].copy()
# Filter out rows that were never really explored (very high regret, zero prob)
# — use rows that the solver actually visited (prob > 0 OR regret < some cutoff)
all_eval = df[(df["prob"] > MIN_PROB_TO_PLOT) | 
              (df["regret"] < df["regret"].quantile(0.95))].copy()

def make_pivot(data, value_col, a_col="a", h_col="h"):
    """Pivot to 2-D grid: rows=h (ascending), cols=a (ascending)."""
    pivot = data.pivot_table(index=h_col, columns=a_col, values=value_col, aggfunc="mean")
    pivot = pivot.sort_index(ascending=True)          # h low→high bottom→top
    pivot = pivot.sort_index(axis=1, ascending=True)  # a left→right
    return pivot

def h_ticklabels(h_values):
    """Replace 30 with '30-44' for display."""
    def fmt(h):
        try:
            return H_LABEL_30 if int(float(h)) == 30 else str(int(float(h)))
        except (ValueError, TypeError):
            return str(h)
    return [fmt(h) for h in h_values]

def a_ticklabels(a_values, max_labels=15):
    """Thin out x-axis labels so they don't overlap."""
    n = len(a_values)
    step = max(1, n // max_labels)
    labels = []
    for i, a in enumerate(a_values):
        labels.append(str(int(a)) if i % step == 0 else "")
    return labels

# ── Colormaps ─────────────────────────────────────────────────────────────────
# Probability: white → deep purple
prob_cmap = mcolors.LinearSegmentedColormap.from_list(
    "prob_purple",
    ["#eeedf8", "#a09be0", "#5349b3", "#261e68"],
)
prob_cmap.set_bad(color="#e8e8e4")   # grey for NaN / unexplored

# Regret: teal (low) → light grey (mid) → coral (high)
regret_cmap = mcolors.LinearSegmentedColormap.from_list(
    "regret_tealcoral",
    ["#1d9e75", "#a8a89a", "#d85a30"],
)
regret_cmap.set_bad(color="#e8e8e4")

# ── Plot helper ───────────────────────────────────────────────────────────────
def plot_heatmap(pivot, cmap, title, cbar_label, power=0.45, fig_scale=1.0):
    """
    Draw a heatmap from a pivot table.
    power: gamma for colour scaling (< 1 pulls out low values).
    """
    data = pivot.values.astype(float)
    
    # Mask NaNs (unexplored)
    masked = np.ma.masked_invalid(data)
    
    vmin = np.nanmin(data[np.isfinite(data)])
    vmax = np.nanmax(data[np.isfinite(data)])
    
    # Gamma-normalise
    norm = mcolors.PowerNorm(gamma=power, vmin=vmin, vmax=vmax)

    n_h, n_a = pivot.shape
    fig_w = max(8, n_a * 0.18 * fig_scale)
    fig_h = max(4, n_h * 0.45 * fig_scale)

    fig, ax = plt.subplots(figsize=(fig_w, fig_h))
    im = ax.imshow(
        masked,
        cmap=cmap,
        norm=norm,
        aspect="auto",
        origin="lower",          # h increases upward
        interpolation="nearest",
    )

    # Axes ticks
    a_vals = list(pivot.columns)
    h_vals = list(pivot.index)

    ax.set_xticks(range(n_a))
    ax.set_xticklabels(a_ticklabels(a_vals), fontsize=8, rotation=90)
    ax.set_yticks(range(n_h))
    ax.set_yticklabels(h_ticklabels(h_vals), fontsize=8)

    ax.set_xlabel("a  (rebate)", fontsize=11, labelpad=6)
    ax.set_ylabel("h  (threshold)", fontsize=11, labelpad=6)
    ax.set_title(title, fontsize=13, pad=10)

    # Colourbar
    cbar = fig.colorbar(im, ax=ax, fraction=0.03, pad=0.02)
    cbar.set_label(cbar_label, fontsize=9)
    cbar.ax.tick_params(labelsize=8)

    # Thin grid lines between cells
    ax.set_xticks(np.arange(-0.5, n_a, 1), minor=True)
    ax.set_yticks(np.arange(-0.5, n_h, 1), minor=True)
    ax.grid(which="minor", color="white", linewidth=0.3, alpha=0.4)
    ax.tick_params(which="minor", bottom=False, left=False)

    fig.tight_layout()
    return fig

# ── Build pivots ──────────────────────────────────────────────────────────────
# Probability pivot — only strategies with meaningful mass
prob_pivot = make_pivot(evaluated, "prob")

# Regret pivot — all evaluated strategies (mask zeros for log/power norm)
regret_pivot = make_pivot(all_eval, "regret")

# ── Draw ──────────────────────────────────────────────────────────────────────
fig1 = plot_heatmap(
    prob_pivot,
    cmap=prob_cmap,
    title="Nash Equilibrium  —  P(a, h)",
    cbar_label="Probability",
    power=0.4,
)

fig2 = plot_heatmap(
    regret_pivot,
    cmap=regret_cmap,
    title="Nash Equilibrium  —  Regret(a, h)",
    cbar_label="Regret",
    power=0.5,
)

fig1.savefig("nash_prob_heatmap.png", dpi=150, bbox_inches="tight")
fig2.savefig("nash_regret_heatmap.png", dpi=150, bbox_inches="tight")
print("Saved: nash_prob_heatmap.png, nash_regret_heatmap.png")

plt.show()