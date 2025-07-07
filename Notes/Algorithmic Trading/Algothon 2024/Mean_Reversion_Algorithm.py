import numpy as np

def getMyPosition(prcSoFar):
    # prcSoFar
    # numpy array 100 x nt
    # e.g. 100 x 250

    # don't do anything for the first day
    # prcSoFar.shape is (100, 250)
    if prcSoFar.shape[1] <= 1: 
        # creates a vector of zeros 
        return np.zeros(prcSoFar.shape[0])

    indxs = [2, 6, 60, 76, 91, 92, 95]
    p = prcSoFar[indxs, :]
    # p is 7 x 250 
    p_log = np.log(p)
    # p_log is 7 x 250 
    p_log_diff = np.diff(p_log, axis=1)
    # p_log_diff is 7 x 249 
    p_log_diff_last = p_log_diff[-1]
    # p_log_diff_last is 7 x 1 
    m = np.mean(p_log_diff_last)
    # m is a floating point val

    # buys is 100 x 1 vector of false
    buys = np.zeros(prcSoFar.shape[0], dtype=bool)
    # (p_log_diff_last < m - 0.0005) is 7 x 1 boolean vector
    np.put(buys, indxs, p_log_diff_last < m - 0.0005)

    sells = np.zeros(prcSoFar.shape[0], dtype=bool)
    np.put(sells, indxs, p_log_diff_last > m + 0.0005)

    # find the maximal position for each stock 
    # (10000 / prcSoFar[:,-1]) does 10000 divided by every element 
    pos_limits = np.ceil(10000 / prcSoFar[:,-1])
    return pos_limits * buys - pos_limits * sells