from tkinter import W
import numpy as np
from typing import Optional
from scipy import stats
import pandas as pd
from statsmodels.tsa.stattools import adfuller
import math

prevPos: Optional[np.array] = None

def getMyPosition(histPrice: np.array):
    global prevPos
    nInst: int
    nDays: int
    nInst, nDays = histPrice.shape

    posDelta: np.array = np.zeros(nInst)

    if nDays > 200:
        prices = histPrice 
        price_mean = prices.mean(axis=1)
        price_sd = np.std(prices, axis=1)
        price_mean_expanded = np.outer(price_mean, np.ones(len(prices[0])))
        price_central = prices - price_mean_expanded
        price_sd_expanded = np.outer(price_sd, np.ones(len(prices[0])))
        price_std = price_central / price_sd_expanded

        data = pd.DataFrame(prices).T
        corr_matrix = data.corr()
        corr_matrix
        
        max_corr = []
        for index, row in corr_matrix.iterrows():
            for i in range(0, len(row)):
                corr = row[i]
                if corr > 0.85 and i > index:
                    max_corr.append((corr, index, i))

        max_corr.sort(key=lambda x: x[0], reverse=True)
        
        pairs_coint = []
        for pair in max_corr:
            inst_1 = pair[1]
            inst_2 = pair[2]
            
            spread = price_std[inst_1] - price_std[inst_2]
            spread_adf = adfuller(spread)
            if spread_adf[1] <= 0.05:
                pairs_coint.append((spread_adf[1], inst_1, inst_2))

        if len(pairs_coint) > 0:
            price_diff = np.ndarray(shape=(len(pairs_coint), nDays))
            for i in range(len(pairs_coint)):
                ints_1 = pairs_coint[i][1]
                inst_2 = pairs_coint[i][2]
                
                price_diff[i] = price_std[ints_1] - price_std[inst_2]
            
            diff_mean = price_diff.mean(axis=1)
            diff_sd = np.std(price_diff, axis=1)
            diff_mean_expanded = np.outer(diff_mean, np.ones(len(price_diff[0])))
            diff_central = price_diff - diff_mean_expanded
            diff_sd_expanded = np.outer(diff_sd, np.ones(len(price_diff[0])))
            z_diff = diff_central / diff_sd_expanded

            for i in range(len(z_diff)):
                point = z_diff[i][-1]
                inst_1, inst_2 = get_inst(i, max_corr)
                if point > 2.0:
                    long(inst_1, prevPos, posDelta)
                    short(inst_2, prevPos, posDelta)
                    print("Pair at: " + str(point))
                elif point < -2.0:
                    short(inst_1, prevPos, posDelta)
                    long(inst_2, prevPos, posDelta)
                    print("Pair at: " + str(point))
                elif abs(point) < 0.5:
                    return_pos(inst_1, prevPos, posDelta)
                    return_pos(inst_2, prevPos, posDelta)

    if prevPos is None:
        prevPos = np.zeros(nInst)
    pos = prevPos + posDelta
    prevPos = pos
    return prevPos

def get_inst(index, corr):
    return (corr[index][1], corr[index][2])

def long(index, prevPos, posDelta):
    pos = prevPos[index] + posDelta[index]
    if pos < 10000:
        print("Long: " + str(index))
        posDelta[index] += 1000

def short(index, prevPos, posDelta):
    pos = prevPos[index] + posDelta[index]
    if pos > -10000:
        print("Short: " + str(index))
        posDelta[index] += -1000
        
def return_pos(index, prevPos, posDelta):
    if prevPos[index] > 0:
        posDelta[index] -= 1000
        print("Return " + str(index))
    elif prevPos[index] < 0:
        posDelta[index] += 1000
        print("Return " + str(index))