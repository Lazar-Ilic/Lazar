wdbc = read.csv('../data/wdbc.csv', header=FALSE)

y = as.numeric(wdbc[,2] == 'M')
X = as.matrix(wdbc[,-c(1,2)])
scrub = which(1:ncol(X) %% 3 == 0)
scrub = 11:30
X = X[,-scrub]

X = cbind(1, scale(X))

glm1 = glm(y~X-1, family='binomial')

coef(glm1)


# Evaluates the negative likelihood of the logit model
# @beta: current guess for coefficients, including intercept
# @y: successes
# @m: sample sizes
# @X: feature matrix (with column of 1's for intercept)
logit_nll = function(beta, y, X, m) {
  psi_hat = drop(X %*% beta)
  sum(m*log(1+exp(psi_hat)) - y*psi_hat)
}

# Evaluates the gradient of the negative
# log likelihood of the logit model
# @beta: current guess for coefficients, including intercept
# @y: successes
# @m: sample sizes
# @X: feature matrix (with column of 1's for intercept)
logit_nll_grad = function(beta, y, X, m) {
  psi_hat = drop(X %*% beta)
  y_hat = m*1/{1+exp(-psi_hat)}
  delta = y_hat - y
  crossprod(X, delta)
}

p = ncol(X)
beta_hat = rnorm(p)
m = rep(1, nrow(X))
obj_val = logit_nll(beta_hat, y, X, m)

step_size = 0.01
n_steps = 10000
obj_tracker = rep(0, n_steps)
beta_tracker = matrix(0, nrow=n_steps, ncol=p)
for(i in 1:n_steps) {
  search_dir = -logit_nll_grad(beta_hat, y, X, m)
  beta_hat = beta_hat + step_size*search_dir
  obj_val = logit_nll(beta_hat, y, X, m)
  obj_tracker[i] = obj_val
  beta_tracker[i,] = beta_hat
}


plot(obj_tracker)

cbind(drop(tail(beta_tracker, 1)), coef(glm1))
