epan_kernel = function(x, b) {
	# epanechnikov kernel with bandwidth b
	(1/b)*pmax(0, 0.75*(1-(x/b)^2))
}

gauss_kernel = function(x, b) {
	# gaussian kernel with bandwidth b
	dnorm(x, 0, b)
}


weights = function(x, xstar, b, kernel = 'gauss'){
	# Calculates the weights for xstar given the previous observations x
	# Arguments:
	#	 x: vector containing the x points
	#	 xstar: target point
	#	 b: bandwidth
	# Returns:
	#	 w: vector of weights for new design point xstar
	# -----------------------------------------------------

	n = length(x)
	w = rep(1/n, n)

	if(kernel == 'gauss') {
		w = gauss_kernel(xstar - x, b)
	} else if(kernel == 'epan') {
		w = epan_kernel(xstar - x, b)
	} else {
		error(paste0(kernel, " kernel not implemented."))
	}
	
	return(w)
}

kernel_smooth = function(x, y, xstar, h, kernel = 'gauss') {
	# Local regression by kernel smoothing
	# Arguments:
	#	 x: design points
	#	 y: responses
	#	 xstar: points where we want to get smoothed function values
	#	 h: bandwidth
	# Returns:
	#	 ystar: smoothed values at xstar

	ybar = mean(y)
	n = length(xstar)
	ystar = rep(ybar, n) 
	
	# Could be much faster: just looping over the grid points
	for(i in 1:length(xstar)) {
		w = weights(x, xstar[i], h, kernel)
		
		# Normalize weights
		if (sum(w) > 0) {
			w = w/sum(w)
		} else {
			w = rep(1/length(x), length(x))
		}
		ystar[i] = sum(w*y)
	}
	
	return(ystar)
}




locreg = function(x, y, xstar, deg, h, kernel = 'gauss'){
	# 	deg: degree of local polynomial
	
	n = length(x)
	nstar = length(xstar)

	# Bookkeeping
	ystar = rep(0, nstar)
	H = matrix(0, nstar, n)
	R = matrix(0, n, deg+1)

 	# Loop over points in xstar
	for (i in 1:nstar) {

		# Compute the weights
		W = weights(x, xstar[i], h, kernel)

		# Compute R for point xstar[i]
		if (deg >= 1) {
			delta = x - xstar[i]
			for(d in 1:(deg+1)) {
				R[,d] = delta^(d-1)
			}
			# Weighted least squares
			RtW = crossprod(R, diag(W))
			smoothing_weights = drop((solve(RtW %*% R) %*% RtW)[1,])
			H[i,] = smoothing_weights
			ystar[i] = sum(smoothing_weights * y)
		} else {
			H[i,] = W/sum(W)
			ystar[i] = sum(smoothing_weights * y)
		}
	}

	list(R = R, ystar = ystar, H = H)
}


locreg.cv = function(x, y, deg, hgrid, kernel = 'epan'){
	# 	deg: degree of local polynomial
	#	hgrid: range of bandwidth values
	n = length(x)
	nh = length(hgrid)
	LOOCV = rep(NA, nh)
	fit_list = list()
	for(i in 1:nh) {
		h = hgrid[i]
		out = locreg(x, y, x, deg, h, kernel)
		LOOCV[h] = sum( (y - out$ystar)^2 / (1 - diag(out$H))^2)
		fit_list[[i]] = out
	}
	best_index = which.min(LOOCV)
	h = hgrid[best_index]

	list(h = h, ystar = fit_list[[best_index]]$ystar, H = fit_list[[best_index]]$H)
}

