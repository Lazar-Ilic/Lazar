import arviz as az
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

from scipy import stats

az.style.use('arviz-darkgrid')

(1 * .5)/(.5 * .5 + 1* .5)

plt.figure(figsize=(10, 8))

n_trials = [0, 1, 2, 3, 4, 8, 16, 32, 50, 150]
data = [0, 1, 1, 1, 1, 4, 6, 9, 13, 48]
theta_real = 0.35

beta_params = [(1, 1), (20, 20), (1, 4)]
dist = stats.beta
x = np.linspace(0, 1, 200)

for idx, N in enumerate(n_trials):
    if idx == 0:
        plt.subplot(4, 3, 2)
        plt.xlabel('θ')
    else:
        plt.subplot(4, 3, idx+3)
        plt.xticks([])
    y = data[idx]
    for (a_prior, b_prior) in beta_params:
        p_theta_given_y = dist.pdf(x, a_prior + y, b_prior + N - y)
        plt.fill_between(x, 0, p_theta_given_y, alpha=0.7)
        # Add Vertical line for Number of Heads divided by Number of Tosses
        try:
            unit_rate_per_toss = y/N
        except ZeroDivisionError:
            unit_rate_per_toss = 0
        plt.axvline(unit_rate_per_toss, ymax=0.3, color='k', linestyle="--")
    plt.axvline(theta_real, ymax=0.3, color='k')
    plt.plot(0, 0, label=f'{N:4d} trials\n{y:4d} heads', alpha=0)
    plt.xlim(0, 1)
    plt.ylim(0, 12)
    plt.legend()
    plt.yticks([])
plt.tight_layout();

# https://github.com/aloctavodia/BAP/blob/master/exercises/Chapter2.ipynb

# Chapter 2 Exercises
import arviz as az
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pymc3 as pm

from scipy import stats

np.random.seed(123)
# Question 1
# Using PyMC3, change the parameters of the prior beta distribution in our_first_model to match those of the previous chapter. Compare the results to the previous chapter. Replace the beta distribution with a uniform one in the interval [0,1]. Are the results equivalent to ? Is the sampling slower, faster or the same? What about using a larger interval, such as [-1,2]? Does the model run? What errors do you get?

trials = 4
theta_real = 0.35  # unknown value in a real experiment
data = stats.bernoulli.rvs(p=theta_real, size=trials)
# Baseline model
# First let us set a baseline model with a  prior. We'll give  a more verbose name to be able to more easily identify it later. It should be noted that string variable names do not have to the same as the object name.

# When evaluating each model the strategy will be the same.

# Run the model
# Read the warning messages
# View the posterior kernel density estimate and traceplot
# Inspect the numerical summary
with pm.Model() as our_first_model:
    # a priori
    θ = pm.Beta('θ Beta(alpha=1, beta=1)', alpha=1., beta=1.)
    # likelihood
    y = pm.Bernoulli('y', p=θ, observed=data)
    trace_baseline = pm.sample(10000, random_seed=123)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ Beta(alpha=1, beta=1)]
# Sampling 4 chains: 100%|██████████| 42000/42000 [00:05<00:00, 7357.36draws/s]
# az.plot_trace(trace_baseline);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f68043feda0>,
#        <matplotlib.axes._subplots.AxesSubplot object at 0x7f6804173d68>]],
#      dtype=object)

baseline_model = az.summary(trace_baseline)
baseline_model
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# θ Beta(alpha=1, beta=1)	0.33	0.18	0.0	0.03	0.65	17358.0	1.0
# Match prior for previous example
# Picking first parameters from page 28
with pm.Model() as our_first_model:
    # a priori
    θ = pm.Beta("θ", alpha=1,beta=1)
    # likelihood
    y = pm.Bernoulli('y', p=θ, observed=data)
    trace = pm.sample(1000, random_seed=123)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ]
# Sampling 4 chains: 100%|██████████| 6000/6000 [00:00<00:00, 7761.98draws/s]
# The acceptance probability does not match the target. It is 0.8832139313883572, but should be close to 0.8. Try to increase the number of tuning steps.
# Replace the beta distribution with a uniform one in the interval [0,1]
with pm.Model() as our_first_model:
    # a priori
    θ = pm.Uniform('θ Uniform(0,1)', lower=0, upper=1)
    # likelihood
    y = pm.Bernoulli('y', p=θ, observed=data)
    trace_uniform_1_1 = pm.sample(10000, random_seed=123)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ Uniform(0,1)]
# Sampling 4 chains: 100%|██████████| 42000/42000 [00:05<00:00, 7891.80draws/s]
# az.plot_trace(trace_uniform_1_1);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f6804b12d30>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f6804b11b70>]],
#       dtype=object)

uniform_prior_0_1 = az.summary(trace_uniform_1_1)
pd.concat([baseline_model, uniform_prior_0_1])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# θ Beta(alpha=1, beta=1)	0.33	0.18	0.0	0.03	0.65	17358.0	1.0
# θ Uniform(0,1)	0.33	0.18	0.0	0.03	0.65	17358.0	1.0
# Discussion
# Both priors produce identical results. This is to be expected as a  prior is exactly the same as a  prior. I encourage you to prove it to yourself by plotting both. Furthermore, the models sampling times are identical as well.

# Replace the beta distribution with a uniform [-1,2]
with pm.Model() as our_first_model:
    # a priori
    θ = pm.Uniform('θ Uniform(-1,2)', lower=-1, upper=2)
    # likelihood
    y = pm.Bernoulli('y', p=θ, observed=data)
    trace_uniform_prior_minus_1_2 = pm.sample(10000, random_seed=123)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ Uniform(-1,2)]
# Sampling 4 chains: 100%|██████████| 42000/42000 [00:05<00:00, 7283.27draws/s]
# There were 1213 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 1355 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 1087 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 1206 divergences after tuning. Increase `target_accept` or reparameterize.
# az.plot_trace(trace_uniform_prior_minus_1_2);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f680567bc88>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f680e782cf8>]],
#       dtype=object)

uniform_prior_minus_1_2 = az.summary(trace_uniform_prior_minus_1_2)
pd.concat([baseline_model, uniform_prior_minus_1_2])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# θ Beta(alpha=1, beta=1)	0.33	0.18	0.0	0.03	0.65	17358.0	1.0
# θ Uniform(-1,2)	0.33	0.18	0.0	0.03	0.65	10694.0	1.0
# Discussion
# Looking at the mean, sd, and HPD values, both results look identical, which is great. However there are three items that raise concerns. We will cover these in depth in Chapter 8 but will note them here as part of the exercise.

# The first is that there are two new warning messages that look something like There were 1179 divergences after tuning. Increase target_accept or reparameterize. Here, the sampler is warning us that something is going wrong with sampling.

# The second is the black bars at the bottom of the traceplot. These also indicate divergences.

# Lastly, when looking at eff_n, which stands for effective number of samples, the  prior has a much lower number than the , meaning that the number of useful samples was much less than the total number of samples drawn.

# This makes sense when asking the question "Can a probabiity be less than 0 or more than 1?". The answer is no, but in our prior we're asking the sampler to "test" prior probability values less than 0 and greater than 1, and when it does so the likelihood function is unable to compute a value.

# Again, we'll cover MCMC diagnostics (and what to do) in much more detail in Chapter 8, but for now it is sufficient to be able to recognize these warnings when they appear.

# Question 2
# Read about the coal mining disaster model that is part of the PyMC3 documentation. Try to implement and run this model by yourself.

# Question 3
# Modify model_g: change the prior for the mean to a Gaussian distribution centered at the empirical mean, and play with a couple of reasonable values for the standard deviation of this prior. How robust/sensitive are the inferences to these changes? What do you think of using a Gaussian, which is an unbounded distribution (goes from  to ), to model bouded data such as this? Remember that we said it is not possible to get values below 0 or above 100.

# First let's load the data and calculate the mean and standard deviation

data = np.loadtxt('../code/data/chemical_shifts.csv')
empirical_mean = np.mean(data)
empirical_std = np.std(data)
empirical_mean, empirical_std
# (53.49645833333333, 3.4200063898474258)
# Next, let's create a model with a prior parametrized by . Since we want to test the effect of various  values, we'll assume that values of [1.5, 3.0, 5.0] are reasonable priors parameters. We'll also add one unreasonable  of 1000 for comparison.

# A benefit of Python is that we can create a loop to run three models and compare results.

summaries = []
sd_priors = [1.5, 3, 5, 1000]

for sd_prior in sd_priors:
    with pm.Model() as model_g:
        # Modified prior to Gaussian
        μ = pm.Normal(f'μ_prior_{sd_prior}', mu=empirical_mean, sd=sd_prior)
        σ = pm.HalfNormal('σ', sd=10)
        y = pm.Normal('y', mu=μ, sd=σ, observed=data)
        trace_g = pm.sample(1000)
        summaries.append(az.summary(trace_g))
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ_prior_1.5]
# Sampling 4 chains: 100%|██████████| 6000/6000 [00:01<00:00, 5632.08draws/s]
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ_prior_3]
# Sampling 4 chains: 100%|██████████| 6000/6000 [00:01<00:00, 5400.77draws/s]
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ_prior_5]
# Sampling 4 chains: 100%|██████████| 6000/6000 [00:01<00:00, 5384.37draws/s]
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ_prior_1000]
# Sampling 4 chains: 100%|██████████| 6000/6000 [00:01<00:00, 5887.95draws/s]
pd.concat(summaries)
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ_prior_1.5	53.50	0.48	0.01	52.59	54.41	4104.0	1.0
# σ	3.54	0.37	0.01	2.92	4.28	2835.0	1.0
# μ_prior_3	53.50	0.49	0.01	52.62	54.44	3742.0	1.0
# σ	3.54	0.38	0.00	2.89	4.28	4066.0	1.0
# μ_prior_5	53.48	0.52	0.00	52.54	54.46	3719.0	1.0
# σ	3.55	0.38	0.00	2.88	4.27	3591.0	1.0
# μ_prior_1000	53.51	0.50	0.01	52.54	54.41	4064.0	1.0
# σ	3.53	0.37	0.00	2.88	4.23	4456.0	1.0
# Looking at the summaries, the combination of model and inference technique seem quite robust to the changes. Even with a prior that is 300x larger than the empirical prior, the posterior values converge to approximately the same result. Computationally there seems to be very little difference.

# Logically however, there could be some question about the choice of an unbounded prior. Since it is not possible to get values below 0 or above 100, it doesn't make practical sense to have a prior that exists for those values. Luckily though, with modern inference methods such as NUTS, the samples can "bypass" questionable priors and still get a good approximation of the posterior.

# Question 4
# Using the data in chemical_shifts.csv, compute the empirical mean and the standard deviation with and without outliers. Repeat the exercise by adding more outliers. Compare those results to the Bayesian estimations using the Gaussian and Student's t distributions from the chapter.

# Let's first compute the mean and standard deviation without removing any data:

data = np.loadtxt('../code/data/chemical_shifts.csv')
empirical_mean, empirical_std = np.mean(data), np.std(data)
empirical_mean, empirical_std
# (53.49645833333333, 3.4200063898474258)
# Then let's let's identify outliers by using the 2x standard deviation methodology:

outlier_mask = ~(np.abs(data-empirical_mean) < empirical_std*2)
data[outlier_mask]
array([63.43, 68.58])
# Removing those two values, let's recompute the mean and standard deviation:

empirical_mean_no_outliers = np.mean(data[~outlier_mask])
empirical_std_no_outliers = np.std(data[~outlier_mask])

empirical_mean_no_outliers, empirical_std_no_outliers
# (52.95260869565218, 2.1950303897892387)
# Notice that the mean has dropped from 53.49 to 52.95, and the standard deviation has dropped from 3.42 to 2.19. Logically this makes sense as the data is "less spread out" when we don't include outliers.

# Let's repeat the exercise but add more outliers. We can do this by repeating the previously identified outliers a couple more times:

# Create an array with the outliers repeated 4 times
additional_outliers = np.repeat(data[outlier_mask],4)

# Concatenate the original data array and the additional outliers
data_more_outliers = np.concatenate([data, additional_outliers])
data_more_outliers
array([51.06, 55.12, 53.73, 50.24, 52.05, 56.4 , 48.45, 52.34, 55.65,
       51.49, 51.86, 63.43, 53.  , 56.09, 51.93, 52.31, 52.33, 57.48,
       57.44, 55.14, 53.93, 54.62, 56.09, 68.58, 51.36, 55.47, 50.73,
       51.94, 54.95, 50.39, 52.91, 51.5 , 52.68, 47.72, 49.73, 51.82,
       54.99, 52.84, 53.19, 54.52, 51.46, 53.73, 51.61, 49.81, 52.42,
       54.3 , 53.84, 53.16, 63.43, 63.43, 63.43, 63.43, 68.58, 68.58,
       68.58, 68.58])
empirical_mean_more_outliers = np.mean(data_more_outliers)
empirical_std_more_outliers = np.std(data_more_outliers)

empirical_mean_more_outliers, empirical_std_more_outliers
# (55.28339285714286, 5.489222647537144)
# The mean and standard deviation both go up in this case. This intuitively makes sense because the distribution needs to "stretch" to include these additional data points that are farther away from the mean.

# Question 5
# Modify the tips example to make it robust to outliers. Try with one shared  for all groups and also with one  per group. Run posterior predictive checks to assess these three models.

tips = pd.read_csv('../code/data/tips.csv')
tip = tips['tip'].values
idx = pd.Categorical(tips['day'],
                     categories=['Thur', 'Fri', 'Sat', 'Sun']).codes
groups = len(np.unique(idx))
# Gaussian Model
with pm.Model() as comparing_groups:
    μ = pm.Normal('μ', mu=0., sd=10., shape=groups)
    σ = pm.HalfNormal('σ', sd=10., shape=groups)
    y = pm.Normal('y', mu=μ[idx], sd=σ[idx], observed=tip)
    trace_normal = pm.sample(5000)
    y_pred_normal = pm.sample_posterior_predictive(trace_normal, 100)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [ν, σ, μ]
# Sampling 4 chains: 100%|██████████| 22000/22000 [00:06<00:00, 3456.31draws/s]
# 100%|██████████| 100/100 [00:00<00:00, 1829.08it/s]
tips_normal = az.from_pymc3(trace=trace_normal, posterior_predictive=y_pred_normal)
axes = az.plot_ppc(tips_normal, figsize=(12,8), mean=False)
axes[0].set_title("Posterior Predictive Check for Normal Tips Model");
Text(0.5, 1.0, 'Posterior Predictive Check for Normal Tips Model')

# Shared  across all groups
with pm.Model() as comparing_groups:
    μ = pm.Normal('μ', mu=0, sd=10, shape=groups)
    σ = pm.HalfNormal('σ', sd=10, shape=groups)
    ν = pm.Exponential('ν', 1/30)
    y = pm.StudentT('y', mu=μ[idx], sd=σ[idx], nu=ν, observed=tip)
    trace_nu_shared = pm.sample(5000)
    y_pred_nu_shared = pm.sample_posterior_predictive(trace_nu_shared, 100)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [ν, σ, μ]
# Sampling 4 chains: 100%|██████████| 22000/22000 [00:06<00:00, 3298.40draws/s]
# 100%|██████████| 100/100 [00:00<00:00, 1741.07it/s]
tips_nu_shared = az.from_pymc3(trace=trace_nu_shared, posterior_predictive=y_pred_nu_shared)
axes = az.plot_ppc(tips_nu_shared, figsize=(12,8), mean=False)
axes[0].set_title("Posterior Predictive Check for Student T Shared ν Tips Model")
# axes[0].set_xlim(-4.5,10);
# (-4.5, 10)

# One  per group
with pm.Model() as comparing_groups:
    μ = pm.Normal('μ', mu=0, sd=10, shape=groups)
    σ = pm.HalfNormal('σ', sd=10, shape=groups)
    ν = pm.Exponential('ν', 1/30, shape=groups)
    y = pm.StudentT('y', mu=μ[idx], sd=σ[idx], nu=ν[idx], observed=tip)
    trace_nu_per_group = pm.sample(5000)
    y_pred_nu_per_group = pm.sample_posterior_predictive(trace_nu_per_group, 100)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [ν, σ, μ]
# Sampling 4 chains: 100%|██████████| 22000/22000 [00:07<00:00, 2979.97draws/s]
# There were 4 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 2 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 2 divergences after tuning. Increase `target_accept` or reparameterize.
# The number of effective samples is smaller than 25% for some parameters.
# 100%|██████████| 100/100 [00:00<00:00, 1616.72it/s]
tips_nu_per_group = az.from_pymc3(trace=trace_nu_per_group, posterior_predictive=y_pred_nu_per_group)
axes = az.plot_ppc(tips_nu_per_group, figsize=(12,8), mean=False)
axes[0].set_title("Posterior Predictive Check for Student T ν per group")
axes[0].set_xlim(-10,10);
# (-10, 10)

# Question 6
# Compute the probability of superiority directly from the posterior (without computing Cohen's d first). You can use the pm.sample_posterior_predictive() function to take a sample from each group. Is it really different from the calculation assuming normality? Can you explain the result?

# The goal is to calculate Cohen's D numerically. We'll do that in 3 steps:

# Fit a distribution of parameters to our data
# Generate posterior predictive distributions for our groups
# Pick data points at random from each group and compare the datapoints in each group
# Step 1: Estimate model parameters per group
tips = pd.read_csv('../code/data/tips.csv')
tip = tips['tip'].values
idx = pd.Categorical(tips['day'],
                     categories=['Thur', 'Fri', 'Sat', 'Sun']).codes
groups = len(np.unique(idx))
with pm.Model() as comparing_groups:
    μ = pm.Normal('μ', mu=0, sd=10, shape=groups)
    σ = pm.HalfNormal('σ', sd=10, shape=groups)
    y = pm.Normal('y', mu=μ[idx], sd=σ[idx], observed=tip)
    trace_cg = pm.sample(5000)
    ppc_cg = pm.sample_posterior_predictive(trace_cg, samples=500)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ]
# Sampling 4 chains: 100%|██████████| 22000/22000 [00:10<00:00, 2187.82draws/s]
# 100%|██████████| 500/500 [00:00<00:00, 2433.49it/s]
flat_tips = az.from_pymc3(trace=trace_cg)
tips_gaussian = az.summary(flat_tips)
tips_gaussian
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ[0]	2.77	0.16	0.0	2.47	3.07	18417.0	1.0
# μ[1]	2.73	0.26	0.0	2.24	3.21	18914.0	1.0
# μ[2]	2.99	0.18	0.0	2.66	3.34	19388.0	1.0
# μ[3]	3.26	0.14	0.0	2.99	3.52	21207.0	1.0
# σ[0]	1.27	0.12	0.0	1.05	1.48	20605.0	1.0
# σ[1]	1.10	0.20	0.0	0.76	1.47	17433.0	1.0
# σ[2]	1.65	0.13	0.0	1.42	1.90	20229.0	1.0
# σ[3]	1.26	0.10	0.0	1.07	1.45	21622.0	1.0
# Step 2: Get posterior predictive values per group
# In our case, let's see if Sunday is superior to Thursday in regards to tips.

# In our code, recall that:

# We have 244 items
# We encoded the string labels of days into "codes" or integers
# Sunday was encoded as 3, Thursday was encoded as 0
# Get our model's predictions for possible tips on Thursday and Sunday
posterior_predictive_thursday = ppc_cg["y"][:,idx==0].flatten()
posterior_predictive_sunday = ppc_cg["y"][:,idx==3].flatten()
# Just to get a sense of the distributions, let's plot them:

# az.plot_kde(posterior_predictive_thursday);
# <matplotlib.axes._subplots.AxesSubplot at 0x7f6808ef1fd0>

# az.plot_kde(posterior_predictive_sunday);
# <matplotlib.axes._subplots.AxesSubplot at 0x7f67ea39add8>

# From visual inspection, it's hard to see the difference between the two groups.

# Step 3: Pick data points at random from each group and compare
# Let's numerically simulate Cohen's D by drawing random samples from both posterior predictive distributions and naively calculating probability

count_superior = 0
samples = 1000
for _ in range(samples):
    thursday_tip_draw = np.random.choice(posterior_predictive_thursday)
    sunday_tip_draw = np.random.choice(posterior_predictive_sunday)
    if thursday_tip_draw > sunday_tip_draw:
        count_superior +=1
        
count_superior/samples
# 0.397
# .397 is very similar to the calculation we obtained in Figure 2.18. This means that, given a tip on Thursday, there is only a 4 in 10 chance that it will be higher than a tip on Sunday. In other words, you should sign up for Sunday shifts if you're looking to make extra money! I encourage you to try changing the idx values to compare other groups.

# For reference, another, more efficient way to compute Cohen's D is possible with numpy broadcasting. The code below is functionally identical to the code above, but by using numpy broadcasting we can write less code and the computation is completed more efficiently:

thursday_tip_draws = np.random.choice(posterior_predictive_thursday, replace=True, size=1000)
sunday_tip_draws = np.random.choice(posterior_predictive_sunday, replace=True, size=1000)

(thursday_tip_draws > sunday_tip_draws).mean()
# 0.402
# Question 7
# Repeat the exercise we did with model_h. This time, without hierarchical structure, use a flat prior such as . Compare the results of both models.

# Generate data
N_samples = [30, 30, 30]
G_samples = [18, 3, 3] # [18, 18, 18]  # [3, 3, 3]  

group_idx = np.repeat(np.arange(len(N_samples)), N_samples)
data = []
for i in range(len(N_samples)):
    data.extend(np.repeat([1, 0], [G_samples[i], N_samples[i]-G_samples[i]]))
# Baseline model
with pm.Model() as model_h:
    μ = pm.Beta('μ', 1., 1.)
    κ = pm.HalfNormal('κ', 10.)
    θ = pm.Beta('θ', alpha=μ*κ, beta=(1.0-μ)*κ, shape=len(N_samples))
    y = pm.Bernoulli('y', p=θ[group_idx], observed=data)
    trace_h = pm.sample(2000)
    ppc_h = pm.sample_posterior_predictive(trace_h, samples=500)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ, κ, μ]
# Sampling 4 chains: 100%|██████████| 10000/10000 [00:02<00:00, 3853.70draws/s]
# 100%|██████████| 500/500 [00:00<00:00, 2952.82it/s]
# az.plot_trace(trace_h);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f67d3416748>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67d342e630>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67e37c6b70>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67e3418f28>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67dea8cc18>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67d3527cc0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67d35519e8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67d34d9550>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67e345ec88>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67d34b7cc0>]],
#       dtype=object)

# az.plot_forest(trace_h);
# (<Figure size 432x576 with 1 Axes>,
#  array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67cb6e3e80>],
#        dtype=object))

baseline_summary = az.summary(trace_h)
baseline_summary
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ	0.30	0.11	0.00	0.10	0.50	7070.0	1.0
# κ	5.74	3.83	0.04	0.51	12.81	6541.0	1.0
# θ[0]	0.55	0.09	0.00	0.40	0.72	7743.0	1.0
# θ[1]	0.13	0.06	0.00	0.03	0.24	7869.0	1.0
# θ[2]	0.13	0.06	0.00	0.03	0.23	7870.0	1.0
baseline_model = az.from_pymc3(trace=trace_h, posterior_predictive=ppc_h)
# az.plot_ppc(baseline_model, figsize=(12,6), mean=False);
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67cb5fa710>],
#       dtype=object)

# Flat model
with pm.Model() as model_h:
    μ = pm.Beta('μ', 1., 1.)
    κ = pm.HalfNormal('κ', 10.)
    θ = pm.Beta('θ', alpha=μ*κ, beta=(1.0-μ)*κ)
    y = pm.Bernoulli('y', p=θ, observed=data)
    trace_non_h = pm.sample(2000)
    ppc_non_h = pm.sample_posterior_predictive(trace_non_h, samples=500)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [θ, κ, μ]
# Sampling 4 chains: 100%|██████████| 10000/10000 [00:02<00:00, 4777.36draws/s]
# 100%|██████████| 500/500 [00:00<00:00, 5313.71it/s]
# az.plot_trace(trace_non_h);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c98cda58>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c98fc898>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c98858d0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c9899be0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c983fc18>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c9865c50>]],
#       dtype=object)

# az.plot_forest(trace_non_h);
# (<Figure size 432x518.4 with 1 Axes>,
#  array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c9b23a58>],
#        dtype=object))

flat_summary = az.summary(trace_non_h)
flat_summary
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ	0.34	0.16	0.00	0.07	0.65	4715.0	1.0
# κ	9.04	6.05	0.12	0.11	19.89	4756.0	1.0
# θ	0.27	0.05	0.00	0.19	0.36	5072.0	1.0
flat_model = az.from_pymc3(trace=trace_non_h, posterior_predictive=ppc_non_h)
# az.plot_ppc(flat_model, figsize=(12,6));
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67cb038a58>],
#       dtype=object)

# Summary comparison
pd.concat([baseline_summary, flat_summary])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ	0.30	0.11	0.00	0.10	0.50	7070.0	1.0
# κ	5.74	3.83	0.04	0.51	12.81	6541.0	1.0
# θ[0]	0.55	0.09	0.00	0.40	0.72	7743.0	1.0
# θ[1]	0.13	0.06	0.00	0.03	0.24	7869.0	1.0
# θ[2]	0.13	0.06	0.00	0.03	0.23	7870.0	1.0
# μ	0.34	0.16	0.00	0.07	0.65	4715.0	1.0
# κ	9.04	6.05	0.12	0.11	19.89	4756.0	1.0
# θ	0.27	0.05	0.00	0.19	0.36	5072.0	1.0
# Discussion
# In the hiearchical model, we get three estimates of , one per each group. So, by using a hierarchical model, we're able to obtain the range of  parameters per group, and not just the average  parameter for all groups.

# Question 8
# Create a hierarchical version of the tips example by partially pooling across the days of the week. Compare the results to those obtained without the hierarchical structure.

# Refer to Question 6 for the non-pooled version of the model.

with pm.Model() as pooled_mu_tips:
    # Pooled Expected mean of tips
    pooled_mean = pm.Normal('pooled_mean', mu=0., sd=10.)
    μ = pm.Normal("μ", mu=pooled_mean, sd=1., shape=groups)
    # Unpooled Standard Deviation of tips
    σ = pm.HalfNormal('σ', sd=10., shape=groups)
    y = pm.Normal('y', mu=μ[idx], sd=σ[idx], observed=tip)
    trace_pooled_tips = pm.sample(5000)
    ppc_pooled_tips = pm.sample_posterior_predictive(trace_pooled_tips, samples=500)
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (4 chains in 4 jobs)
# NUTS: [σ, μ, pooled_mean]
# Sampling 4 chains: 100%|██████████| 22000/22000 [00:09<00:00, 2273.84draws/s]
# 100%|██████████| 500/500 [00:00<00:00, 2623.33it/s]
# az.plot_trace(trace_pooled_tips);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8a0c7f0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c89b0588>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c89db5c0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c89845f8>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8b342b0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8a57ac8>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8954cc0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c88ffb00>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c88a5b70>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c88d0b38>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c887aba8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c882a4e0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67ca5cf860>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c89ee128>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8a286d8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8a848d0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8b1c630>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x7f67c8be87f0>]],
#       dtype=object)

pooled_tips_dataset = az.from_pymc3(trace=trace_pooled_tips)
tips_pooled_summary = az.summary(pooled_tips_dataset)
tips_pooled_summary
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# pooled_mean	2.93	0.51	0.0	1.97	3.87	24855.0	1.0
# μ[0]	2.78	0.16	0.0	2.48	3.08	24501.0	1.0
# μ[1]	2.75	0.25	0.0	2.27	3.23	20600.0	1.0
# μ[2]	2.99	0.17	0.0	2.65	3.31	23902.0	1.0
# μ[3]	3.25	0.14	0.0	2.98	3.52	24137.0	1.0
# σ[0]	1.27	0.12	0.0	1.05	1.49	22418.0	1.0
# σ[1]	1.10	0.20	0.0	0.76	1.47	19218.0	1.0
# σ[2]	1.65	0.13	0.0	1.42	1.89	23071.0	1.0
# σ[3]	1.26	0.11	0.0	1.07	1.46	24078.0	1.0
pd.concat([tips_gaussian, tips_pooled_summary])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# μ[0]	2.77	0.16	0.0	2.47	3.07	18417.0	1.0
# μ[1]	2.73	0.26	0.0	2.24	3.21	18914.0	1.0
# μ[2]	2.99	0.18	0.0	2.66	3.34	19388.0	1.0
# μ[3]	3.26	0.14	0.0	2.99	3.52	21207.0	1.0
# σ[0]	1.27	0.12	0.0	1.05	1.48	20605.0	1.0
# σ[1]	1.10	0.20	0.0	0.76	1.47	17433.0	1.0
# σ[2]	1.65	0.13	0.0	1.42	1.90	20229.0	1.0
# σ[3]	1.26	0.10	0.0	1.07	1.45	21622.0	1.0
# pooled_mean	2.93	0.51	0.0	1.97	3.87	24855.0	1.0
# μ[0]	2.78	0.16	0.0	2.48	3.08	24501.0	1.0
# μ[1]	2.75	0.25	0.0	2.27	3.23	20600.0	1.0
# μ[2]	2.99	0.17	0.0	2.65	3.31	23902.0	1.0
# μ[3]	3.25	0.14	0.0	2.98	3.52	24137.0	1.0
# σ[0]	1.27	0.12	0.0	1.05	1.49	22418.0	1.0
# σ[1]	1.10	0.20	0.0	0.76	1.47	19218.0	1.0
# σ[2]	1.65	0.13	0.0	1.42	1.89	23071.0	1.0
# σ[3]	1.26	0.11	0.0	1.07	1.46	24078.0	1.0
# az.plot_forest(pooled_tips_dataset);
# (<Figure size 432x691.2 with 1 Axes>,
#  array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c9a9add8>],
#        dtype=object))

# az.plot_forest(flat_tips);
# (<Figure size 432x590.4 with 1 Axes>,
#  array([<matplotlib.axes._subplots.AxesSubplot object at 0x7f67c9755c18>],
#        dtype=object))

# Question 9
# PyMC3 can create directed acyclic graphs (DAGs) from models that are very similar to Kruschke's diagrams. You can obtain them using the pm.model_to_graphviz() function. To generate DAGs, you may need to install graphviz using the command conda install -c conda-forge python-graphviz. Generate a DAG for each model in this chapter.

pm.model_to_graphviz(pooled_mu_tips)
# 4
# 244
pooled_mean ~ Normal
μ ~ Normal
σ ~ HalfNormal
y ~ Normal
# A last note before finishing up: besides the exercises you'll find at the end of each chapter, you can always try to (and probably should) think of problems you are interested in and how to apply what you have learned to that problem. Maybe you will need to define your problem in a different way, or maybe you will need to expand or modify the models you have learned. If you think this task is beyond your current skills, note down the problem and come back to it after reading another chapter in this book. Eventually, if the book does not answer your questions, check the PyMC3 examples or ask a question on PyMC's Discourse.

# https://github.com/aloctavodia/BAP/blob/master/exercises/Chapter3.ipynb

# Chapter 3 Exercises
import os
import arviz as az
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pymc3 as pm

from IPython.display import SVG, display
from pandas.plotting import parallel_coordinates
from scipy import stats
from theano import shared, tensor

np.random.seed(seed=0)
az.style.use('arviz-darkgrid')
# WARNING (theano.configdefaults): install mkl with `conda install mkl-service`: No module named 'mkl'
# Question 1
# Check the following definition of a probabilistic model. Identify the likelihood, the prior and the posterior:

# The priors in this model are:

# The likelihood in our model is:

# And the posterior will be a distribution over and, but the posterior is not directly specified in the model (it is the result of Bayes formula!).

# Question 2
# For the model in exercise 1, how many parameters will the posterior have? In other words, how many dimensions will it have?

# There are two parameters in this model:  and . So the posterior is 2-dimensional.

# Question 3
# Write Bayes' theorem for the model in exercise 1.

# Without expanding the denominator:

# Expanding the denominator:

# Question 4
# Check the following model. Identify the linear model and the likelihood. How many parameters does the posterior have?

# The linear model is:

# The likelihood in our model is:

# The posterior will have three parameters:

# Question 5
# For the model in exercise 1, assume that you have a dataset with 57 data points coming from a Gaussian with a mean of 4 and a standard deviation of 0.5. Using PyMC3, compute:

# The posterior distribution
# The prior distribution
# The posterior predictive distribution
# The prior predictive distribution
# Tip: Besides pm.sample(), PyMC3 has other functions to compute samples.

# For this exercise we will generate 57 datapoints from a distribution of :

data = stats.norm(4,.5).rvs(size=57)
with pm.Model() as model:
    mu = pm.Normal("mu", 0, 10)
    sd = pm.HalfNormal("sd", 25)
    y = pm.Normal("y,", mu, sd, observed=data)
    # Compute both prior, and prior predictive
    prior_predictive = pm.sample_prior_predictive()
    # Compute posterior
    trace = pm.sample()
    # Compute posterior predictive
    posterior_predictive = pm.sample_posterior_predictive(trace)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [sd, mu]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:01<00:00, 1084.35draws/s]
# The acceptance probability does not match the target. It is 0.8806704207811868, but should be close to 0.8. Try to increase the number of tuning steps.
# 100%|██████████| 1000/1000 [00:00<00:00, 1292.64it/s]
dataset = az.from_pymc3(trace = trace, posterior_predictive = posterior_predictive, prior = prior_predictive)
dataset
# Inference data with groups:
# 	> posterior
# 	> sample_stats
# 	> posterior_predictive
# 	> prior
# 	> observed_data
# Let's plot the prior distributions to get a sense of what the Bayesian model's estimations without data

# The plot_posterior method can be used to plot priors as well
az.plot_posterior(dataset.prior, var_names=["mu", "sd"]);
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x1c1b207cc0>,
#        <matplotlib.axes._subplots.AxesSubplot object at 0x1c1b19dcc0>],
#       dtype=object)

# Now let's plot the posterior, to check the distributions after update:

# Compare above plot to posterior distribution below, as well as to original parameters in distribution
az.plot_posterior(dataset)
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x1c282e27b8>,
#        <matplotlib.axes._subplots.AxesSubplot object at 0x1c2831deb8>],
#       dtype=object)

# The exercise also asks for the prior predictive values. We'll need to do some data manipulation to get the data into a format we can use with ArviZ:

dataset.prior

# <xarray.Dataset>
# Dimensions:   (chain: 1, draw: 500, y,_dim_0: 57)
# Coordinates:
#   * chain     (chain) int64 0
#   * draw      (draw) int64 0 1 2 3 4 5 6 7 8 ... 492 493 494 495 496 497 498 499
#   * y,_dim_0  (y,_dim_0) int64 0 1 2 3 4 5 6 7 8 ... 48 49 50 51 52 53 54 55 56
# Data variables:
#     sd        (chain, draw) float64 0.5084 33.7 19.04 ... 79.27 4.737 33.71
#     y,        (chain, draw, y,_dim_0) float64 3.632 2.833 1.979 ... -33.26 11.49
#     mu        (chain, draw) float64 3.025 -6.343 -3.627 ... -6.78 12.98 -23.64
#     sd_log__  (chain, draw) float64 -0.6766 3.517 2.947 ... 4.373 1.556 3.518
# Attributes:
#     created_at:                 2019-03-16T02:34:03.270827
#     inference_library:          pymc3
#     inference_library_version:  3.6
# Let's also plot the prior predictive values, we'll need to do some data manipulation to get the data into a format we can use with ArviZ

print(dataset.prior["y,"].values.shape)
prior_predictive = dataset.prior["y,"].values.flatten()
prior_predictive.shape
# (1, 500, 57)
# (28500,)
az.plot_kde(prior_predictive);
# <matplotlib.axes._subplots.AxesSubplot at 0x1c2872b3c8>

# We can them compare this to the posterior predictive distribution:

az.plot_ppc(dataset);
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x1c28da19b0>],
      dtype=object)

# Question 6
# Execute model_g using NUTS (the default sampler) and then using Metropolis. Compare the results using ArviZ functions like plot_trace and plot_pairs. Center the variable  and repeat the exercise. What conclusion can you draw from this?

np.random.seed(1)
N = 100
alpha_real = 2.5
beta_real = 0.9
eps_real = np.random.normal(0, 0.5, size=N)

x = np.random.normal(10, 1, N)
y_real = alpha_real + beta_real * x
y = y_real + eps_real
with pm.Model() as model_g:
    α = pm.Normal('α', mu=0, sd=10)
    β = pm.Normal('β', mu=0, sd=1)
    ϵ = pm.HalfCauchy('ϵ', 5)
    μ = pm.Deterministic('μ', α + β * x)
    y_pred = pm.Normal('y_pred', mu=μ, sd=ϵ, observed=y)
%%time
with model_g:
    trace_nuts_non_centered = pm.sample(draws=500)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:07<00:00, 316.12draws/s]
# The acceptance probability does not match the target. It is 0.8790052122255555, but should be close to 0.8. Try to increase the number of tuning steps.
# The estimated number of effective samples is smaller than 200 for some parameters.
# CPU times: user 3.09 s, sys: 565 ms, total: 3.65 s
# Wall time: 12.9 s

nuts_non_centered_dataset = az.from_pymc3(trace=trace_nuts_non_centered)

az.plot_trace(trace_nuts_non_centered, var_names=['α', 'β', 'ϵ']);

# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c147f8c50>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c14831240>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c1485de80>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2144f780>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c14616278>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c21479f60>]],
#       dtype=object)

az.plot_pair(trace_nuts_non_centered, var_names=['α', 'β', 'ϵ']);
# [array([[<matplotlib.axes._subplots.AxesSubplot object at 0x105f21d68>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c21bcc4e0>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c21bf3908>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x109498d30>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x105f21d68>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c21bcc4e0>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c21bf3908>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x109498d30>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x105f21d68>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c21bcc4e0>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c21bf3908>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x109498d30>]],
#        dtype=object)]

%%time
with model_g:
    step = pm.Metropolis()
    trace_mh_non_centered = pm.sample(draws=500, step=step)

# Multiprocess sampling (2 chains in 2 jobs)
# CompoundStep
# >Metropolis: [ϵ]
# >Metropolis: [β]
# >Metropolis: [α]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:01<00:00, 1594.40draws/s]
# The gelman-rubin statistic is larger than 1.4 for some parameters. The sampler did not converge.
# The estimated number of effective samples is smaller than 200 for some parameters.
# CPU times: user 2.31 s, sys: 249 ms, total: 2.56 s
# Wall time: 3.26 s
az.plot_trace(trace_mh_non_centered, var_names=['α', 'β', 'ϵ']);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c13cdbeb8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c22280ac8>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c13e70240>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c13f21cc0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c145fc6a0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c13d4b5c0>]],
#       dtype=object)

az.summary(trace_nuts_non_centered, var_names=['α', 'β', 'ϵ'])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# α	2.10	0.53	0.05	1.13	3.03	143.0	1.02
# β	0.94	0.05	0.00	0.85	1.03	140.0	1.02
# ϵ	0.45	0.04	0.00	0.39	0.52	503.0	1.00
az.summary(trace_mh_non_centered, var_names=['α', 'β', 'ϵ'])
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# α	2.74	0.43	0.15	2.21	3.47	1.0	3.27
# β	0.88	0.04	0.01	0.81	0.93	1.0	3.14
# ϵ	0.45	0.03	0.00	0.40	0.51	109.0	1.00
# Now let's standardize the variables and take samples again. We don't need to redefine the model, but we'll do so for clarities sake:

# standardize the data
x_centered = (x - x.mean())/x.std()
y_centered = (y - y.mean())/y.std()
with pm.Model() as model_g_centered:
    α = pm.Normal('α', mu=0, sd=10)
    β = pm.Normal('β', mu=0, sd=1)
    ϵ = pm.HalfCauchy('ϵ', 5)
    μ = pm.Deterministic('μ', α + β * x_centered)
    y_pred = pm.Normal('y_pred', mu=μ, sd=ϵ, observed=y_centered)

%%time
with model_g_centered:
    trace_nuts_centered = pm.sample()

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:02<00:00, 770.39draws/s] 
# CPU times: user 2.59 s, sys: 218 ms, total: 2.81 s
# Wall time: 4.43 s
az.plot_trace(trace_nuts_centered, var_names=['α', 'β', 'ϵ']);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c22edaeb8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c22fdc9e8>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c22e5b080>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c22ddd240>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c23012e80>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2303c780>]],
#       dtype=object)

az.plot_pair(trace_nuts_centered, var_names=['α', 'β', 'ϵ']);
# [array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c234bd898>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23577e10>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c235e7828>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23611c50>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c234bd898>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23577e10>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c235e7828>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23611c50>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c234bd898>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23577e10>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c235e7828>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c23611c50>]],
#        dtype=object)]

%%time
with model_g_centered:
    step = pm.Metropolis()
    trace_mh_centered = pm.sample(step=step)

# Multiprocess sampling (2 chains in 2 jobs)
# CompoundStep
# >Metropolis: [ϵ]
# >Metropolis: [β]
# >Metropolis: [α]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:01<00:00, 1409.95draws/s]
# The estimated number of effective samples is smaller than 200 for some parameters.
# CPU times: user 2.14 s, sys: 192 ms, total: 2.33 s
# Wall time: 2.96 s
az.plot_trace(trace_mh_centered, var_names=['α', 'β', 'ϵ'])
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c23b678d0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c23b85e10>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c23bcdb38>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c22b52a20>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c22b3e668>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c23cf7ac8>]],
#       dtype=object)

az.plot_pair(trace_mh_centered, var_names=['α', 'β', 'ϵ']);
# [array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2418aeb8>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c241a1668>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2421fa90>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c24249208>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2418aeb8>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c241a1668>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2421fa90>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c24249208>]],
#        dtype=object),
#  array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2418aeb8>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c241a1668>],
#         [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2421fa90>,
#          <matplotlib.axes._subplots.AxesSubplot object at 0x1c24249208>]],
#        dtype=object)]

# Looking through the plots there's a couple things to note.

# Metropolis Hastings is less effective at sampling than NUTS. This is indicated by:

# The Metropolis Hasting trace plots looking "square" when compared the NUTS traceplot. This is due to the sampler getting "stuck" at a value. The kernel density estimates of each chain have "squiggly" topologies The effective number of samples for Non Centered Metropolis Hastings is 1 One thing to note though is that Metropolis Hastings does sample faster than NUTS. While the results aren't great, credit is due where it's deserved!

# Diving into the problem further, we can see that  and  are linearly correlated. Metropolis Hastings does not sample well when toplogies have such shapes. We'll talk more about this in Chapter 8, but for now note how centering x helps somewhat with the Metropolis Hasting sampler, as centering decorrelates and parameters.

# The biggest takeaway is the effectiveness of NUTS, regardless of topology in these two cases. This is not to say NUTS can handle anything you throw at it, there are some topologies that are hard, but by and large NUTS does quite well in many situations.

# Question 7
# Use the howell dataset to create a linear model of the weight () against the height (). Exclude subjects that are younger than 18. Explain the results.

# Let's import the dataset and create a mask for people older than 18:

howell = pd.read_csv("../code/data/howell.csv", delimiter=";")
howell.head()
# height	weight	age	male
# 0	151.765	47.825606	63.0	1
# 1	139.700	36.485807	63.0	0
# 2	136.525	31.864838	65.0	0
# 3	156.845	53.041915	41.0	1
# 4	145.415	41.276872	51.0	0
age_18_mask = howell["age"] > 18
# A good first step is before diving into statistics is to look at the data and ask if it make sense. In my experience taller people tend to weigh more than shorter people. Let's check the data to be sure.

howell[age_18_mask].plot(kind="scatter", x="weight", y="height");
# <matplotlib.axes._subplots.AxesSubplot at 0x1c242b70f0>

# When looking at the plot above this is with consistent our expectations. As weight increases, height increases as well. From visual inspection, it looks like a linear fit with some noise is best. In this case we will assume constant variance. Let's create a model:

height = howell["height"]
weight = howell["weight"]
with pm.Model() as over_18_heights:
    α = pm.Normal("α", sd=10)
    β = pm.Normal("β", sd=10)
    ϵ = pm.HalfNormal("ϵ", sd=10)
    weight_shared = shared(weight[age_18_mask].values * 1.)
    μ = pm.Deterministic("μ", α+β*weight_shared)
    height_pred = pm.Normal("height_pred", mu=μ, sd=ϵ, observed = height[age_18_mask])
    trace_over_18_heights = pm.sample(tune=2000)
    ppc_over_18_heights = pm.sample_posterior_predictive(trace_over_18_heights, samples=2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:14<00:00, 347.37draws/s]
# The acceptance probability does not match the target. It is 0.8949160386428021, but should be close to 0.8. Try to increase the number of tuning steps.
# 100%|██████████| 2000/2000 [00:02<00:00, 105.64it/s]
az.plot_trace(trace_over_18_heights, var_names = ["α","β", "ϵ"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c22802f60>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c22b27b00>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c13574f98>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x105efd588>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c23876898>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c23a03cc0>]],
#       dtype=object)

# Looking at the traceplot it looks like the inference engine was able to explore the posterior adequately. Let's plot the regression and the hpd.

fig, ax = plt.subplots()

ax.plot(weight[age_18_mask], height[age_18_mask], "C0.")
μ_m = trace_over_18_heights["μ"].mean(0)
ϵ_m = trace_over_18_heights["ϵ"].mean()

ax.plot(weight[age_18_mask], μ_m, c="k")
az.plot_hpd(weight[age_18_mask], trace_over_18_heights["μ"], credible_interval=.98)
az.plot_hpd(weight[age_18_mask], ppc_over_18_heights["height_pred"], credible_interval=.98, color="gray")
fig.suptitle("Weight vs Height fit and posterior predictive checks");
Text(0.5, 0.98, 'Weight vs Height fit and posterior predictive checks')

# From visual inspection the average parameters of the fit look quite good, and the 98% interval of the posterior predictive checks covers most of the distribution. Overall, it looks like a linear fit is great for height vs weight for people over 18!

# Question 8
# For four subjects, we get the weights (45.73, 65.8, 54.2, 32.59), but not their heights. Using the model from the previous exercise, predict the height for each subject, together with their 50% and 94% HPDs.

# Tip 1: Check the coal mining disaster example in PyMC3's documentation.

# Tip 2: Use shared variables.

# Using our previous fit, we can generate predictions for the height of people with various weights:

weights = (45.73, 65.8, 54.2, 32.59)
weight_shared.set_value([45.73])
ppc = pm.sample_posterior_predictive(trace_over_18_heights, samples=2000, model=over_18_heights)
# 100%|██████████| 2000/2000 [00:02<00:00, 885.08it/s]
ppc_first_col = ppc["height_pred"][:,0]
az.plot_kde(ppc_first_col);
# <matplotlib.axes._subplots.AxesSubplot at 0x1c2202f3c8>

# The reason we take the 0th column is that, in the current version of PyMC3, pm.sample_ppc returns an array of size. This makes total sense when you want to do posterior predictive checks, as you want to check that the simulations/predictions have the same size/shape as the observations. But when you just want to make predictions at values other that the input data, that restriction does not apply. In summary, I consider this a limitation of the current implementation of pm.sample_ppc.

# Question 9
# Repeat exercise 7, this time including those below 18 years old. Explain the results.

# Let's take a look at the data again, now without the age limit:

howell.plot(kind="scatter", x="weight", y="height");
# <matplotlib.axes._subplots.AxesSubplot at 0x1c261d4cc0>

# By removing the age limit we notice a different trend. At lower weights, a single unit of weight generally corresponds to more height. At higher weights however the height still goes up, but by a lesser amount. There also seems to be more "spread" in the higher weights, than in the lower weights.

# Intuitively again this makes sense. Weight is a proxy for age, and when born the variability in height and weight is smaller than for adults. Additionally children tend to grow in both height and weight. Once humans reach adulthood, the height is mostly fixed, and the weight unfortunately changes all too easily.

# Another thing to note is the shape of the distribution: it no longer looks linear throughout, but instead looks more like a curve. We could use a square root linear fit, like earlier in the chapter, but we instead will use a logarithmic fit. We will also model the noise term to be correlated with weight, as heights seem to vary more when weights get higher.

with pm.Model() as heights:
    α = pm.Normal("α", sd=10)
    β = pm.Normal("β", sd=10)
    γ = pm.HalfNormal("γ", sd=10)
    δ = pm.HalfNormal("δ", sd=10)
    weight_shared = shared(weight.values * 1.)
    μ = pm.Deterministic("μ", α+β*tensor.log(weight_shared))
    ϵ = pm.Deterministic("ϵ", γ+δ*weight_shared)
    height_pred = pm.Normal("height_pred", mu=μ, sd=ϵ, observed = height)
    trace_heights = pm.sample(tune=2000)
    ppc_heights = pm.sample_posterior_predictive(trace_heights, samples=2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [δ, γ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:15<00:00, 332.59draws/s]
# 100%|██████████| 2000/2000 [00:02<00:00, 947.82it/s]
az.plot_trace(trace_heights, var_names = ["α","β", "γ", "δ"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2be2c4e0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2be3eb00>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2bf2dcf8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2bf4cb70>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2bf75588>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2bf9c9b0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2bfbbcc0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2bfe7710>]],
#       dtype=object)

fig, ax = plt.subplots()

ax.plot(weight, height, "C0.")
μ_m = trace_heights["μ"].mean(0)

order = np.argsort(weight)
ax.plot(weight[order], μ_m[order], c="k")

az.plot_hpd(weight, trace_heights["μ"], credible_interval=.98)
az.plot_hpd(weight, ppc_heights["height_pred"], credible_interval=.98, color="gray")

fig.suptitle("Weight vs Height fit and posterior predictive checks");
Text(0.5, 0.98, 'Weight vs Height fit and posterior predictive checks')

# Let's also plot the noise as a function of weight:

fig, ax = plt.subplots()
ax.plot(weight, trace_heights["ϵ"].mean(0))
az.plot_hpd(weight, trace_heights["ϵ"], credible_interval=.98);
# <matplotlib.axes._subplots.AxesSubplot at 0x1c2c376780>

# We can see that in lower weight ranges there tends to be less variability in height than for bigger weight ranges (i.e when people are older). This makes sense intuitively, as humans start out roughly the same in their earlier years, and tend to become more different in physical dimensions as they grow older in age and weight.

# Question 10
# It is known that for many species the weight does not scale with the height, but with the logarithm of the weight. Use this information to fit the howell data (including subjects from all ages). Do one more model, this time without using the logarithm but instead a second order polynomial. Compare and explain both results.

# We did the logarithm bit in the previous exercise, so let's directly fit the model with a 2nd order polynomial that follows this definition:

# Note that we could have used the dot product like in the model_mlr example, but in this model we chose to explicitly split out the terms.

with pm.Model() as heights_polynomial:
    α = pm.Normal("α", sd=10)
    β = pm.Normal("β", sd=10, shape=2)
    γ = pm.HalfNormal("γ", sd=10)
    δ = pm.HalfNormal("δ", sd=10)
    weight_shared = shared(weight.values * 1.)
    μ = pm.Deterministic("μ", α + β[0] * weight_shared + β[1] * weight_shared**2)
    ϵ = pm.Deterministic("ϵ", γ + δ * weight_shared)
    height_pred_polynomial = pm.Normal("height_pred", mu=μ, sd=ϵ, observed=height)
    trace_heights_polynomial = pm.sample(tune=2000)
    ppc_heights_polynomial = pm.sample_posterior_predictive(trace_heights_polynomial, samples=2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [δ, γ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:31<00:00, 161.01draws/s]
# 100%|██████████| 2000/2000 [00:01<00:00, 1282.82it/s]

az.plot_trace(trace_heights_polynomial, var_names = ["α","β", "γ", "δ"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2ff6bef0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2ff8a400>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c302dbe10>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c30305828>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c3032ec50>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c30355ac8>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c2ff63128>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c3039f630>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c303c9a20>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c303f0dd8>]],
#       dtype=object)

fig, ax = plt.subplots()

ax.plot(weight, height, "C0.")
μ_m = trace_heights_polynomial["μ"].mean(0)
ϵ_m = trace_heights_polynomial["ϵ"].mean(0)

# ax.plot(weight, μ_m, c="k")
az.plot_hpd(weight, trace_heights_polynomial["μ"], credible_interval=.98)
az.plot_hpd(weight, ppc_heights_polynomial["height_pred"], credible_interval=.98, color="gray")
fig.suptitle("Weight vs Height fit and posterior predictive checks");

# For weights up until around ~50 units, the polynomial fit looks good. However past that point the curve starts dropping. Inuitively this does not make sense. This phenonemon is not a property of our data, but of our model choice. Polynomial functions always have to make N-1 turns, where N is the degree of the polynomial. This doesn't necessarily make our model useless, it seems to do a good job in certain parts of the domain, but as a statistical modeler, it's up to you to understand the tools in your toolbox and the tradeoffs of each.

# Question 11
# Think about a model that's able to fit the first three dataset from the Anscombe quartet. Also, think about a model to fit the fourth dataset.

# Below are all four datasets from Anscombe's Quartet
title

# A model that might fit the first three models is a polynomial regression of the form:

# For the more linear datasets the model could have a low value for, and for the second dataset the model would be able to fit the non linearity.

# For the last dataset there seems to be two distinct patterns, a cluster of points at x=8 and one at x=19. We could model this one with two groups as follows:

df = pd.read_csv(os.path.join("..", "code", "data", "anscombe.csv"))
df = df.loc[df["group"] == "IV", ["x", "y"]]
idx = (df["x"] == 8).astype(int)
idx
33    1
34    1
35    1
36    1
37    1
38    1
39    1
40    0
41    1
42    1
43    1

# Name: x, dtype: int64
with pm.Model() as anscombe:
    # Two groups of points with independent parameters
    mu = pm.Normal("mu", sd=10, shape=2)
    sd = pm.HalfNormal("sd", sd=10)
    y = pm.Normal("y", mu=mu[idx], sd=sd, observed=df["y"].values)
    trace_4 = pm.sample(draws=10000)
    ppc = pm.sample_posterior_predictive(trace_4)

/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
Auto-assigning NUTS sampler...
Initializing NUTS using jitter+adapt_diag...
/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
Multiprocess sampling (2 chains in 2 jobs)
NUTS: [mu, sd]
Sampling 2 chains:   0%|          | 0/21000 [00:00<?, ?draws/s]/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
Sampling 2 chains: 100%|██████████| 21000/21000 [00:27<00:00, 777.75draws/s]
There was 1 divergence after tuning. Increase `target_accept` or reparameterize.
  0%|          | 0/20000 [00:00<?, ?it/s]/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
  0%|          | 1/20000 [00:01<6:25:14,  1.16s/it]/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.
  rval = inputs[0].__getitem__(inputs[1:])
100%|██████████| 20000/20000 [00:19<00:00, 1044.96it/s]
az.plot_trace(trace_4);
/Users/canyon/.local/lib/python3.7/site-packages/theano/tensor/subtensor.py:2197: FutureWarning: Using a non-tuple sequence for multidimensional indexing is deprecated; use `arr[tuple(seq)]` instead of `arr[seq]`. In the future this will be interpreted as an array index, `arr[np.array(seq)]`, which will result either in an error or a different result.

rval = inputs[0].__getitem__(inputs[1:])
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c24f9b9b0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c24cb9da0>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x1c24ebdef0>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x10e24ed30>],
#        [<matplotlib.axes._subplots.AxesSubplot object at 0x10e27d978>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x10e2abc88>]],
#       dtype=object)

# Question 12
# See in the code accompanying the book the model_t2 (and the data associated with it). Experiment with priors for, like the non-shifted exponential and gamma priors (they are commented in the code below). Plot the prior distribution, to ensure that you understand them. An easy way to do this is to just comment the likelihood in the model and check the trace plot. A more efficient way though is to use the pm.sample_prior_predictive() function instead of pm.sample().

ans = pd.read_csv('../code/data/anscombe.csv')
x_4 = ans[ans.group == 'IV']['x'].values
y_4 = ans[ans.group == 'IV']['y'].values

with pm.Model() as model_t2:
    α = pm.Normal('α', mu=0, sd=100)
    β = pm.Normal('β', mu=0, sd=1)
    ϵ = pm.HalfCauchy('ϵ', 5)
    ν = pm.Exponential('ν', 1/30)
    # ν = pm.Gamma('ν', mu=20, sd=15)
    # ν = pm.Gamma('ν', 2, 0.1)
    y_pred = pm.StudentT('y_pred', mu=α + β * x_4, sd=ϵ, nu=ν, observed=y_4)
    prior_v_exp = pm.sample_prior_predictive(2000)
    trace_v_exp = pm.sample(2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ν, ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:16<00:00, 308.57draws/s]
data_exp = az.from_pymc3(trace=trace_v_exp, prior=prior_v_exp)
az.plot_trace(data_exp.prior, var_names=["ν"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2fa98dd8>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2fa75ba8>]],
#       dtype=object)

with pm.Model() as model_t2:
    α = pm.Normal('α', mu=0, sd=100)
    β = pm.Normal('β', mu=0, sd=1)
    ϵ = pm.HalfCauchy('ϵ', 5)
    # ν = pm.Exponential('ν', 1/30)
    ν = pm.Gamma('ν', mu=20, sd=15)
    #ν = pm.Gamma('ν', 2, 0.1)
    y_pred = pm.StudentT('y_pred', mu=α + β * x_4, sd=ϵ, nu=ν, observed=y_4)
    prior_v20_15 = pm.sample_prior_predictive(2000)
    trace_v_20 = pm.sample(2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ν, ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:14<00:00, 355.57draws/s]
data_20 = az.from_pymc3(trace=trace_v_20, prior=prior_v20_15)
az.plot_trace(data_20.prior, var_names=["ν"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2ce6af60>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2cd3fd30>]],
#       dtype=object)

with pm.Model() as model_t2:
    α = pm.Normal('α', mu=0, sd=100)
    β = pm.Normal('β', mu=0, sd=1)
    ϵ = pm.HalfCauchy('ϵ', 5)
    # ν = pm.Exponential('ν', 1/30)
    # ν = pm.Gamma('ν', mu=20, sd=15)
    ν = pm.Gamma('ν', 2, 0.1)
    y_pred = pm.StudentT('y_pred', mu=α + β * x_4, sd=ϵ, nu=ν, observed=y_4)
    prior_v2_01 = pm.sample_prior_predictive(2000)
    trace_v_2_01 = pm.sample(2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [ν, ϵ, β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:11<00:00, 453.04draws/s]
data_2 = az.from_pymc3(trace=trace_v_2_01, prior=prior_v2_01)
az.plot_trace(data_2.prior, var_names=["ν"]);
# array([[<matplotlib.axes._subplots.AxesSubplot object at 0x1c2cd62208>,
#         <matplotlib.axes._subplots.AxesSubplot object at 0x1c2dd1c3c8>]],
#       dtype=object)

# Question 13
# For the unpooled_model, change the value of sd for the  prior. Try values of 1 and 100. Explore how the estimated slopes change for each group. Which group is more affected by this change?

N = 20
M = 8
idx = np.repeat(range(M-1), N)
idx = np.append(idx, 7)
np.random.seed(314)

alpha_real = np.random.normal(2.5, 0.5, size=M)
beta_real = np.random.beta(6, 1, size=M)
eps_real = np.random.normal(0, 0.5, size=len(idx))

y_m = np.zeros(len(idx))
x_m = np.random.normal(10, 1, len(idx))
y_m = alpha_real[idx] + beta_real[idx] * x_m + eps_real
x_centered = x_m - x_m.mean()

# Let's loop through a couple standard deviation values for the slope parameter of each group:

sd_values = [1, 10, 100]
all_traces = {}

for sd_value in sd_values:
    with pm.Model() as unpooled_model:
        α_tmp = pm.Normal('α_tmp', mu=0, sd=10, shape=M)
        β = pm.Normal('β', mu=0, sd=sd_value, shape=M)
        ϵ = pm.HalfCauchy('ϵ', 5)
        ν = pm.Exponential('ν', 1/30)
        y_pred = pm.StudentT('y_pred', mu=α_tmp[idx] + β[idx] * x_centered,sd=ϵ, nu=ν, observed=y_m)
        α = pm.Deterministic('α', α_tmp - β * x_m.mean())
        unpooled_model_trace = pm.sample(2000)
        all_traces[sd_value] = unpooled_model_trace

all_traces[10]
all_summaries = []
for sd, trace in all_traces.items():
    summary = az.summary(az.from_pymc3(trace=trace))
    summary["group"] =  f"sd_{sd}"
    summary.reset_index(inplace=True)
    #summary. = summary.index +
    all_summaries.append(summary)
    
summaries_df = pd.concat(all_summaries)
beta = summaries_df[summaries_df["index"].str.contains("β")]
beta = beta[["group", "mean","index"]]
beta_p = beta.pivot(index="group", columns="index")
beta_p.columns = beta_p.columns.droplevel(0)
beta_p.reset_index(inplace=True)
beta_p
parallel_coordinates(beta_p, "group")

# As we increase the standard deviation of the beta prior (the slope parameter), we see that for most of the groups the effect is neglible. However, for group 7 the prior has a strong effect on the posterior estimation because group 7 only has one data point and the unpooled model doesn't consider the datapoints in the other groups. There simply isn't enough data to "wash out" the prior distribution in this case.

# Question 14
# Using the model hierarchical_model, repeat Figure 3.18, the one with the eight groups and the eight lines, but this time add the uncertainty to the linear fit.

N = 20
M = 8
idx = np.repeat(range(M-1), N)
idx = np.append(idx, 7)
np.random.seed(314)

alpha_real = np.random.normal(2.5, 0.5, size=M)
beta_real = np.random.beta(6, 1, size=M)
eps_real = np.random.normal(0, 0.5, size=len(idx))

y_m = np.zeros(len(idx))
x_m = np.random.normal(10, 1, len(idx))
y_m = alpha_real[idx] + beta_real[idx] * x_m + eps_real

with pm.Model() as hierarchical_model:
    # hyper-priors
    α_μ_tmp = pm.Normal('α_μ_tmp', mu=0, sd=10)
    α_σ_tmp = pm.HalfNormal('α_σ_tmp', 10)
    β_μ = pm.Normal('β_μ', mu=0, sd=10)
    β_σ = pm.HalfNormal('β_σ', sd=10)
    # priors
    α_tmp = pm.Normal('α_tmp', mu=α_μ_tmp, sd=α_σ_tmp, shape=M)
    β = pm.Normal('β', mu=β_μ, sd=β_σ, shape=M)
    ϵ = pm.HalfCauchy('ϵ', 5)
    ν = pm.Exponential('ν', 1/30)
    y_pred = pm.StudentT('y_pred', mu=α_tmp[idx] + β[idx] * x_centered,sd=ϵ, nu=ν, observed=y_m)
    α = pm.Deterministic('α', α_tmp - β * x_m.mean())
    α_μ = pm.Deterministic('α_μ', α_μ_tmp - β_μ * x_m.mean())
    α_σ = pm.Deterministic('α_sd', α_σ_tmp - β_μ * x_m.mean())
    trace_hm = pm.sample(1000)
    ppc_lines = pm.sample_posterior_predictive(trace_hm, samples=500)
alpha = trace_hm.get_values("α")[369, 1]
beta = trace_hm.get_values("β")[369, 1]
# Get 20 random samples for chain
chain_length =1000
random_draws = np.random.randint(0, chain_length-1, 20)

_, ax = plt.subplots(2, 4, figsize=(10, 5), sharex=True, sharey=True,constrained_layout=True)
ax = np.ravel(ax)
j, k = 0, N
x_range = np.linspace(x_m.min(), x_m.max(), 10)
for i in range(M):
    ax[i].scatter(x_m[j:k], y_m[j:k])
    ax[i].set_xlabel(f'x_{i}')
    ax[i].set_ylabel(f'y_{i}', labelpad=17, rotation=0)
    # We add this one line to plot uncertainty. At least two data points must be present in group.
    for random_draw in random_draws:
        alpha = trace_hm.get_values("α")[random_draw, i]
        beta = trace_hm.get_values("β")[random_draw, i]
        ax[i].plot(x_m, alpha + beta*x_m, 'C1-', alpha=0.5)
        # ax[i].plot(x_m, alpha + beta*x_m)
    alpha_m = trace_hm['α'][:, i].mean()
    beta_m = trace_hm['β'][:, i].mean()
    ax[i].plot(x_range, alpha_m + beta_m * x_range, c='k',label=f'y = {alpha_m:.2f} + {beta_m:.2f} * x')
    plt.xlim(x_m.min()-1, x_m.max()+1)
    plt.ylim(y_m.min()-1, y_m.max()+1)
    j += N
    k += N

# Question 15
# Re-run the model_mlr example, this time without centering the data. Compare the uncertainty in the  parameter for one case and the other. Can you explain these results?

# Tip: Remember the definition of the  parameter (also known as the intercept).

np.random.seed(314)
N = 100
alpha_real = 2.5
beta_real = [0.9, 1.5]
eps_real = np.random.normal(0, 0.5, size=N)

X = np.array([np.random.normal(i, j, N) for i, j in zip([10, 2], [1, 1.5])]).T
X_mean = X.mean(axis=0, keepdims=True)
# X_centered = X - X_mean
y = alpha_real + np.dot(X, beta_real) + eps_real
with pm.Model() as model_mlr:
    α_tmp = pm.Normal('α_tmp', mu=0, sd=10)
    β = pm.Normal('β', mu=0, sd=1, shape=2)
    ϵ = pm.HalfCauchy('ϵ', 5)
    μ = α_tmp + pm.math.dot(X, β)
    α = pm.Deterministic('α', α_tmp - pm.math.dot(X_mean, β))
    y_pred = pm.Normal('y_pred', mu=μ, sd=ϵ, observed=y)
    trace_mlr = pm.sample(2000)
az.summary(trace_mlr, var_names=['α', 'β', 'ϵ'])

# With the non-centered data,  changes to compensate for the position of the points. In other words,  needs to compensate  distance up or down since the  values are no longer centered around the  axis.

# Question 16
# Read and run this notebook from PyMC3's documentation

# Question 17
# Choose a dataset that you find interesting and use it with the simple linear regression model. Be sure to explore the results using ArviZ functions and compute the Pearson correlation coefficient. If you do not have an interesting dataset, try searching online, for example here or there.

# https://github.com/aloctavodia/BAP/blob/master/exercises/Chapter4.ipynb

# Chapter 4 Exercises
import arviz as az
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pymc3 as pm
import seaborn as sns
import theano.tensor as tt
from scipy import stats
from scipy.special import expit as logistic

np.random.seed(123)
# Exercise 1
# Re-run the first model using the petal length and then petal width variables. What are the main differences in the results? How wide or narrow is the 95% HPD interval in each case?

iris = pd.read_csv('../code/data/iris.csv')
df = iris.query("species == ('setosa', 'versicolor')")
y_0 = pd.Categorical(df['species']).codes

varnames = ['α', 'β', 'bd']
for feature in ["sepal_length", "petal_width", "petal_length"]:
    x_n = feature
    x_0 = df[x_n].values
    x_c = x_0 - x_0.mean()
    with pm.Model() as model_0:
        α = pm.Normal('α', mu=0, sd=10)
        β = pm.Normal('β', mu=0, sd=10)
        μ = α + pm.math.dot(x_c, β)    
        θ = pm.Deterministic('θ', pm.math.sigmoid(μ))
        bd = pm.Deterministic('bd', -α/β)
        yl = pm.Bernoulli('yl', p=θ, observed=y_0)
        trace_0 = pm.sample(1000)  
        print("Feature {} summary".format(feature))
        print(az.summary(trace_0, varnames, credible_interval=.95))

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1391.68draws/s]
# Feature sepal_length summary
#     mean    sd  mc error  hpd 2.5%  hpd 97.5%   eff_n  r_hat
# α   0.31  0.32      0.00     -0.32       0.96  1731.0    1.0
# β   5.40  1.00      0.02      3.55       7.43  1531.0    1.0
# bd -0.06  0.06      0.00     -0.17       0.06  1788.0    1.0
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1170.33draws/s]
# There was 1 divergence after tuning. Increase `target_accept` or reparameterize.
# The number of effective samples is smaller than 25% for some parameters.
# Feature petal_width summary
#      mean    sd  mc error  hpd 2.5%  hpd 97.5%  eff_n  r_hat
# α    0.61  1.83      0.06     -2.77       4.65  645.0    1.0
# β   18.41  5.61      0.15      8.65      29.26  446.0    1.0
# bd  -0.04  0.09      0.00     -0.22       0.13  814.0    1.0
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1104.36draws/s]
# There were 22 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 36 divergences after tuning. Increase `target_accept` or reparameterize.
# The number of effective samples is smaller than 25% for some parameters.
# Feature petal_length summary
#      mean    sd  mc error  hpd 2.5%  hpd 97.5%  eff_n  r_hat
# α    3.37  4.10      0.15     -3.53      12.31  582.0    1.0
# β   12.98  5.64      0.08      3.76      23.78  371.0    1.0
# bd  -0.28  0.28      0.01     -0.81       0.22  704.0    1.0
# From the results, we can see that the bd variable's HPD is the smallest with sepal length, and increases with petal_width and petal_length.

# Exercise 2
# Repeat exercise 1, this time using a Student's t-distribution as a weakly informative prior. Try different values of .

for nu in [1, 10, 30]:
    x_0 = df["petal_length"].values
    x_c = x_0 - x_0.mean()
    with pm.Model() as model_0:
        # Priors have been changed
        α = pm.StudentT('α', nu=nu, mu=0, sd=10)
        β = pm.StudentT('β', nu=nu, mu=0, sd=10)
        μ = α + pm.math.dot(x_c, β)    
        θ = pm.Deterministic('θ', pm.math.sigmoid(μ))
        bd = pm.Deterministic('bd', -α/β)
        yl = pm.Bernoulli('yl', p=θ, observed=y_0)
        trace_0 = pm.sample(1000)
        print(f"Feature {feature} nu {nu} summary")
        print(az.summary(trace_0, varnames, credible_interval=.95))

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:06<00:00, 442.69draws/s]
# There were 660 divergences after tuning. Increase `target_accept` or reparameterize.
# The acceptance probability does not match the target. It is 0.5723934984887481, but should be close to 0.8. Try to increase the number of tuning steps.
# There were 172 divergences after tuning. Increase `target_accept` or reparameterize.
# The estimated number of effective samples is smaller than 200 for some parameters.
# Feature petal_length nu 1 summary
#       mean      sd  mc error  hpd 2.5%  hpd 97.5%  eff_n  r_hat
# α     4.95   13.41      1.15    -10.62      27.76  126.0   1.00
# β   137.73  450.93     81.03      3.59     598.05   41.0   1.03
# bd   -0.17    0.25      0.04     -0.73       0.17   49.0   1.01
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:03<00:00, 879.48draws/s] 
#There were 20 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 37 divergences after tuning. Increase `target_accept` or reparameterize.
# The number of effective samples is smaller than 25% for some parameters.
# Feature petal_length nu 10 summary
#      mean    sd  mc error  hpd 2.5%  hpd 97.5%  eff_n  r_hat
# α    4.03  4.56      0.14     -3.52      13.52  434.0    1.0
# β   14.50  6.94      0.40      3.71      27.74  334.0    1.0
# bd  -0.29  0.28      0.01     -0.83       0.18  543.0    1.0
# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1032.88draws/s]
# There were 55 divergences after tuning. Increase `target_accept` or reparameterize.
# There were 48 divergences after tuning. Increase `target_accept` or reparameterize.
# The number of effective samples is smaller than 25% for some parameters.
# Feature petal_length nu 30 summary
#      mean    sd  mc error  hpd 2.5%  hpd 97.5%  eff_n  r_hat
# α    3.94  4.30      0.20     -2.79      13.68  327.0   1.00
# β   14.01  5.98      0.38      4.00      25.55  369.0   1.01
# bd  -0.28  0.28      0.01     -0.83       0.19  329.0   1.00

# Exercise 3
# Go back to the first example, the logistic regression for classifying setosa or versicolor given sepal length. Try to solve the same problem using a simple linear regression model, as we saw in chapter 3. How useful is linear regression compared to logistic regression? Can the result be interpreted as a probability?

# Tip: check whether the values of  are restricted to the interval [0,1].

x_n = "sepal_length"
x_0 = df[x_n].values
x_c = x_0 - x_0.mean()

with pm.Model() as model_0:
    α = pm.Normal('α', mu=0, sd=10)
    β = pm.Normal('β', mu=0, sd=10)
    sd = pm.HalfNormal("sd", sd=1)
    μ = α + pm.math.dot(x_c, β)
    yl = pm.Normal('yl', mu=μ, sd=sd, observed=y_0)
    trace_linear = pm.sample(1000)
    posterior_predictive_linear = pm.sample_posterior_predictive(trace_linear)
    print(az.summary(trace_linear, credible_interval=.95))

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [sd, β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1139.65draws/s]
# 100%|██████████| 2000/2000 [00:01<00:00, 1088.84it/s]
#     mean    sd  mc error  hpd 2.5%  hpd 97.5%   eff_n  r_hat
# α   0.50  0.04       0.0      0.43       0.57  3075.0    1.0
# β   0.57  0.05       0.0      0.46       0.67  3047.0    1.0
# sd  0.35  0.02       0.0      0.30       0.40  2519.0    1.0
data = az.from_pymc3(trace=trace_linear, posterior_predictive=posterior_predictive_linear)
az.plot_ppc(data);
# array([<matplotlib.axes._subplots.AxesSubplot object at 0x1c28401ba8>],
#       dtype=object)

# From the posterior predictive checks, this model is not very useful. We are trying to estimate the probability of a species given sepal_length, but a number of the posterior predictive check values are below 0 and above 1. As such, the result cannot be interpreted as a probability.

# Exercise 4
# In the example from the "Interpreting the coefficients of a logistic regression" section, we changed sepal_length by 1 unit. Using figure 4.6, corroborate that the value of log_odds_versicolor_i corresponds to the value of probability_versicolor_i. Do the same for log_odds_versicolor_f and probability_versicolor_f. Just by noting that log_odds_versicolor_f - log_odds_versicolor_i is negative, what can you say about the probability? Use figure 4.6 to help you. Is this result clear to you from the definition of log-odds?

df = iris.query("species == ('setosa', 'versicolor')") 
y_1 = pd.Categorical(df['species']).codes 
x_n = ['sepal_length', 'sepal_width'] 
x_1 = df[x_n].values
with pm.Model() as model_1: 
    α = pm.Normal('α', mu=0, sd=10) 
    β = pm.Normal('β', mu=0, sd=2, shape=len(x_n)) 
    μ = α + pm.math.dot(x_1, β) 
    θ = pm.Deterministic('θ', 1 / (1 + pm.math.exp(-μ))) 
    bd = pm.Deterministic('bd', -α/β[1] - β[0]/β[1] * x_1[:,0])
    yl = pm.Bernoulli('yl', p=θ, observed=y_1) 
    trace_1 = pm.sample(2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:17<00:00, 287.70draws/s]
# The acceptance probability does not match the target. It is 0.8848631965762076, but should be close to 0.8. Try to increase the number of tuning steps.
varnames = ['α', 'β'] 
summary = az.summary(trace_1, var_names=varnames)
summary
# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# α	-9.24	4.59	0.11	-17.84	-0.47	1504.0	1.0
# β[0]	4.71	0.88	0.03	3.03	6.34	1370.0	1.0
# β[1]	-5.22	1.01	0.02	-7.25	-3.56	1567.0	1.0
x_1 = 4.5  # sepal_length
x_2 = 3   # sepal_width 

log_odds_versicolor_i = (summary['mean'] * [1, x_1, x_2]).sum()
probability_versicolor_i = logistic(log_odds_versicolor_i)

log_odds_versicolor_f = (summary['mean'] * [1, x_1, x_2+1]).sum()
probability_versicolor_f = logistic(log_odds_versicolor_f)

log_odds_versicolor_f - log_odds_versicolor_i, probability_versicolor_f - probability_versicolor_i
# (-5.219999999999999, -0.02387657278569843)
# The value of -5.22 is consistent with the summary and our "hand check". A log odds value of -5.22 means that as  increases by one unit, the probability that the species is versicolor decreases. Or, equivalently, as sepal width increases, the probability that the flower is versicolor decreases.

# We can verify this with a quick plot:

colors = df["species"].replace({'setosa':"blue", 'versicolor':"green"})
df.plot(kind="scatter", x="sepal_length", y="sepal_width", c=colors);
# <matplotlib.axes._subplots.AxesSubplot at 0x1c2afee748>

# We see that, as sepal width increases from 3 to 4, we get further away from the green dots, reducing the probability that the flower we're seeing is of the versicolor species.

# Question 5
# Use the same example from the previous exercise. For model_1, check how much the log-odds change when increasing sepal_length from 5.5 to 6.5 (spoiler: it should be 4.66). How much does the probability change? How does this increase compared to when we increase sepal_length from 4.5 to 5.5?

# Values for sepal length are directly added in the log_odds_line
x_1 = 4.5  # sepal_length
x_2 = 3   # sepal_width 

for i in (0,1):
    log_odds_versicolor_i = (summary['mean'] * [1, x_1 + i, x_2]).sum()
    probability_versicolor_i = logistic(log_odds_versicolor_i)
    log_odds_versicolor_f = (summary['mean'] * [1, x_1 + i + 1, x_2]).sum()
    probability_versicolor_f = logistic(log_odds_versicolor_f)
    print(f"""sepal_length_i {x_1 + i}, sepal_length_f {x_1 + i + 1}
    Log Odds Change {log_odds_versicolor_f - log_odds_versicolor_i}
    Probability Change {probability_versicolor_f - probability_versicolor_i}
    """)
sepal_length_i 4.5, sepal_length_f 5.5
    Log Odds Change 4.709999999999999
    Probability Change 0.7080309252764029
sepal_length_i 5.5, sepal_length_f 6.5
    Log Odds Change 4.710000000000001
    Probability Change 0.26467417655124303

# From the calculation above we see that while the log-odds change stays constant, as it should in linear regression, the probability change is not as large from 5.5 to 6.5 as it is from 4.5 to 5.5. Looking at the graphic this intuitively makes sense as well. When sepal length is at 4.5, the chance that the species is versicolor is very small. When sepal length jumps to 5.5, this probability gets a lot bigger. This means that subsequently going from 5.5 to 6.5 still increases the probability of versicolor, but not as much - because, well, at 5.5 there is already a good chance that the species we're seeing is versicolor.

# Exercise 6
# In the example for dealing with unbalanced data, change df = df[45:] to df = df[22:78]. This will keep roughly the same number of data points, but now the classes will be balanced. Compare the new result with the previous ones. Which one is more similar to the example using the complete dataset?

iris = pd.read_csv('../code/data/iris.csv')

df = iris.query("species == ('setosa', 'versicolor')") 
df = df[22:78]

y_3 = pd.Categorical(df['species']).codes 
x_n = ['sepal_length', 'sepal_width'] 
x_3 = df[x_n].values

varnames = ['α', 'β'] 
with pm.Model() as model_3: 
    α = pm.Normal('α', mu=0, sd=10) 
    β = pm.Normal('β', mu=0, sd=2, shape=len(x_n)) 
    μ = α + pm.math.dot(x_3, β) 
    θ = 1 / (1 + pm.math.exp(-μ)) 
    bd = pm.Deterministic('bd', -α/β[1] - β[0]/β[1] * x_3[:,0]) 
    yl = pm.Bernoulli('yl', p=θ, observed=y_3) 
    trace_3 = pm.sample(1000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:09<00:00, 320.29draws/s]
# The acceptance probability does not match the target. It is 0.8827315277894231, but should be close to 0.8. Try to increase the number of tuning steps.
az.plot_trace(trace_3, varnames);

idx = np.argsort(x_3[:,0]) 
bd = trace_3['bd'].mean(0)[idx]

plt.scatter(x_3[:,0], x_3[:,1], c= [f'C{x}' for x in y_3]) 
plt.plot(x_3[:,0][idx], bd, color='k')

az.plot_hpd(x_3[:,0], trace_3['bd'], color='k')

plt.xlabel(x_n[0]) 
plt.ylabel(x_n[1]);

/Users/canyon/.miniconda3/envs/bap/lib/python3.6/site-packages/scipy/signal/_savitzky_golay.py:187: RankWarning: Polyfit may be poorly conditioned
  xx_edge, polyorder)

# The decision boundary in this plot looks more like the unfiltered dataset as the blue data points are largely not contained in the boundary decision's 95% HPD. This indicates that the balanced model, even with less data points, is better able to distinguish between classes.

# Exercise 7
# Suppose instead of a softmax regression we use a simple linear model by coding setosa = 0, versicolor = 1 and virginica = 2. Under the simple linear regression model, what will happen if we switch the coding? Will we get the same or different results?

# Lets run the model to have data points for a discussion:

iris = sns.load_dataset('iris')
y_s = pd.Categorical(iris['species']).codes
x_n = iris.columns[:-1]
x_s = iris[x_n].values
x_s = (x_s - x_s.mean(axis=0)) / x_s.std(axis=0)

with pm.Model() as model_s:
    α = pm.Normal('α', mu=0, sd=5, shape=3)
    β = pm.Normal('β', mu=0, sd=5, shape=(4, 3))
    μ = pm.Deterministic('μ', α + pm.math.dot(x_s, β))
    θ = tt.nnet.softmax(μ)
    yl = pm.Categorical('yl', p=θ, observed=y_s)
    trace_s = pm.sample(2000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 5000/5000 [00:39<00:00, 90.06draws/s]
print(trace_s['μ'].shape)
print(trace_s['μ'][:,0,0].mean())
# (4000, 150, 3)
# 20.50240089583297
data_pred = trace_s['μ'].mean(0)
data_pred[:5]
array([[ 20.5024009 ,   6.48490714, -27.0838455 ],
       [ 17.39770936,   7.02248623, -24.56869099],
       [ 19.88486309,   6.2033202 , -26.23990539],
       [ 18.74471434,   5.99731255, -24.90962857],
       [ 21.56848135,   6.03376081, -27.70047043]])

# Conceptual Understanding
# Note the shape of the trace. The dimensions should read as follows: we have 4000 estimations of the 3 softmax class values for each of the 150 rows in the dataset.

# Discussion
# If we changed the softmax model to a linear regression model a couple things would change. First, the interpretation of the final output would be different. A softmax prediction estimates the probability of each class, whereas a linear regression would just provide one number as an estimate for the class. The other problem is that a linear regression would output continous values across all real numbers, and how to define when one class starts and another ends is unclear.

# Exercise 8
# Compare the likelihood of the logistic model versus the likelihood of the LDA model. Use the sample_posterior_predictive function to generate predicted data and compare the types of data you get for both cases. Be sure you understand the difference between the types of data the model predicts.

iris = pd.read_csv('../code/data/iris.csv')
df = iris.query("species == ('setosa', 'versicolor')") 
y_3 = pd.Categorical(df['species']).codes 
x_n = 'sepal_length'
x_3 = df[x_n].values

# Logistic Regression model (Discriminative)

with pm.Model() as logistic_model:
    α = pm.Normal("α", mu=0, sd=10)
    β = pm.Normal("β", mu=0, sd=10)
    μ =  α + pm.math.dot(x_3, β)
    θ = pm.Deterministic("θ", pm.math.sigmoid(μ))
    bd = pm.Deterministic("bd", -α / β )
    y1= pm.Bernoulli("y1", p=θ, observed=y_3)
    trace_logistic = pm.sample(2000)
    ppc_logistic = pm.sample_posterior_predictive(trace_logistic)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β, α]
# Sampling 2 chains: 100%|██████████| 2000/2000 [00:05<00:00, 385.63draws/s]
# The estimated number of effective samples is smaller than 200 for some parameters.
# 100%|██████████| 1000/1000 [00:00<00:00, 1586.40it/s]

# Linear Discriminant Analysis (Discriminative)

with pm.Model() as lda_model:
    σ = pm.HalfNormal("σ", sd=10)
    μ = pm.Normal("μ", mu=0, sd=10, shape=2)
    setosa = pm.Normal('setosa', mu=μ[0], sd=σ, observed=x_3[:50])
    versicolor = pm.Normal("versicolor", mu=μ[1], sd=σ, observed=x_3[50:])
    bd = pm.Deterministic('bd', (μ[0] + μ[1]) / 2)
    trace_lda = pm.sample(1000)
    ppc_lda = pm.sample_posterior_predictive(trace_lda)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [μ, σ]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1168.67draws/s]
# The acceptance probability does not match the target. It is 0.8892659742708484, but should be close to 0.8. Try to increase the number of tuning steps.
# 100%|██████████| 2000/2000 [00:02<00:00, 692.00it/s]
# The likelihood of the logisitic regression model is as follows and the likelihood of the Linear Discriminative Analysis are.

# In the logistic regression we are not estimating the properties of the sepal length. We are merely fitting parameters of the inverse link function. In the LDA model we are estimating the sepal length distributions directly.

ppc_logistic["y1"][0]
array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0,
       0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
       0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1,
       0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
       0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1])
ppc_lda["setosa"][0]
array([5.59852617, 5.09568788, 5.26277595, 4.67319903, 4.970315  ,
       4.53590922, 4.08561261, 5.88398851, 4.70309481, 5.01470091,
       4.86725988, 4.77155467, 5.38988434, 6.06846195, 4.13818591,
       4.93774811, 4.96063805, 4.62652669, 4.95666654, 5.01235388,
       4.54895677, 4.24667044, 5.08459178, 4.47643989, 4.26908685,
       4.03809189, 5.0624234 , 5.21945325, 5.01683427, 4.70436585,
       5.14984516, 5.13216414, 5.14483366, 4.70856442, 4.15395632,
       4.42284433, 3.91473064, 4.88724366, 4.69020283, 4.88200706,
       4.98517253, 5.754367  , 4.80215121, 5.51413712, 4.25565248,
       4.62582676, 5.05025521, 5.54609099, 4.9940747 , 5.13240562])

# When comparing the posterior predictive, it can be seen that the logistic model is binary, estimating either 0 or 1, while the LDA model has real numbers that generally look like sepal lengths. This follows our understandings of the models: the logistic regression makes predictions as to which class a particular sepal length belongs to, whereas the LDA model makes predictions about the sepal lengths directly.

# Exercise 9
# Using the fish data, extend the ZIP_reg model to include the persons variable as part of a linear model. Include this variable to model the number of extra zeros. You should get a model that includes two linear models: one connecting the number of children and the presence/absence of a camper to the Poisson rate (as in the example we saw), and another connecting the number of persons to the  variable. For the second case, you will need a logistic inverse link!

fish_data = pd.read_csv('../code/data/fish.csv')

with pm.Model() as ZIP_reg:
    # ψ = pm.Beta('ψ', 1, 1)
    α = pm.Normal('α', 0, 10)
    β = pm.Normal('β', 0, 10, shape=2)
    θ = pm.math.exp(α + β[0] * fish_data['child'] + β[1] * fish_data['camper'])
    α_person = pm.Normal('α_person', 0, 10)
    β_person = pm.Normal('β_person', 0, 10)
    ψ = pm.math.sigmoid(α_person + β_person * fish_data['persons'])
    yl = pm.ZeroInflatedPoisson('yl', ψ, θ, observed=fish_data['count'])
    trace_ZIP_reg = pm.sample(1000)
az.plot_trace(trace_ZIP_reg);

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [β_person, α_person, β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:07<00:00, 451.29draws/s]

# Exercise 10
# Use the data for the robust logistic example to feed a non-robust logistic regression model and to check that the outliers actually affected the results. You may want to add or remove outliers to better understand the effect of the estimation on a logistic regression and the robustness of the model introduced in this chapter.

iris = sns.load_dataset("iris") 
df = iris.query("species == ('setosa', 'versicolor')") 

y_0 = pd.Categorical(df['species']).codes 
x_n = 'sepal_length'  
x_0 = df[x_n].values 
y_0 = np.concatenate((y_0, np.ones(6, dtype=int))) 
x_0 = np.concatenate((x_0, [4.2, 4.5, 4.0, 4.3, 4.2, 4.4])) 
x_c = x_0 - x_0.mean() 

plt.plot(x_c, y_0, 'o', color='k');

# Let's take the robust logistic regression from the chapter and make it non robust:

with pm.Model() as non_rlg:
    α = pm.Normal("α", mu=0, sd=10)
    β = pm.Normal("β", mu=0, sd=10)
    μ = α + β * x_c
    θ = pm.Deterministic("θ", pm.math.sigmoid(μ))
    bd = pm.Deterministic("bd", -α/β)
    # Short Circuit Robust regression
    # π = pm.Beta("π", 1, 1)
    # p = π *.5 + (1-π)*θ
    p = θ
    y = pm.Bernoulli("y", p=p, observed=y_0)
    trace_rlg = pm.sample(1000)

# Auto-assigning NUTS sampler...
# Initializing NUTS using jitter+adapt_diag...
# Multiprocess sampling (2 chains in 2 jobs)
# NUTS: [π, β, α]
# Sampling 2 chains: 100%|██████████| 3000/3000 [00:02<00:00, 1023.28draws/s]

varnames = ['α', 'β', 'bd']
az.summary(trace_rlg, varnames)

# mean	sd	mc error	hpd 3%	hpd 97%	eff_n	r_hat
# α	0.23	0.24	0.01	-0.24	0.67	2338.0	1.0
# β	2.38	0.48	0.01	1.55	3.36	2242.0	1.0
# bd	-0.10	0.10	0.00	-0.30	0.10	2516.0	1.0

theta = trace_rlg['θ'].mean(axis=0)
idx = np.argsort(x_c)

plt.vlines(trace_rlg['bd'].mean(), 0, 1, color='k')
bd_hpd = az.hpd(trace_rlg['bd'])
plt.fill_betweenx([0, 1], bd_hpd[0], bd_hpd[1], color='k', alpha=0.5)

plt.scatter(x_c, np.random.normal(y_0, 0.02), marker='.', color=[f'C{x}' for x in y_0])
plt.plot(x_c[idx], theta[idx], color='C2', lw=3)
theta_hpd = az.hpd(trace_rlg['θ'])[idx]
plt.fill_between(x_c[idx], theta_hpd[:,0], theta_hpd[:,1], color='C2', alpha=0.5)

plt.xlabel(x_n)
plt.ylabel('θ', rotation=0)

# use original scale for xticks
locs, _ = plt.xticks() 
plt.xticks(locs, np.round(locs + x_0.mean(), 1))
plt.savefig('B11197_04_13.png', dpi=300);

# Compare this plot to figure 4.13. Note that the HPD for the decision boundary is wider, reflecting the additional uncertainty. This is also reflected in the slope which is more gradual. This is reflected both in the plot, but also the beta parameter (15.77 for robust model versus 2.38 for the non-robust model).

# Exercise 11
# Read and run the following notebooks from PyMC3's documentation:

# GLM: Linear regression
# GLM: Robust Linear Regression
# GLM: Hierarchical Linear Regression