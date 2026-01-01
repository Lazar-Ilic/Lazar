library(tidyverse)
library(moderndive)

greenbuildings = read.csv('../data/greenbuildings.csv')

# Let's examine the "green premium"
# starting point: define revenue per sq ft, as the rent times
# the leasing rate (0-100 scale), divided by 100.
# this is how much actual revenue the property brings in per square ft.
greenbuildings = mutate(greenbuildings,
                        rev_psf = Rent * leasing_rate/100)

# using lm to get coefs and std. errors
lm1 = lm(rev_psf ~ green_rating + City_Market_Rent + age + class_a + class_b, data=greenbuildings)

# a regression table that I like better than "summary"
moderndive::get_regression_table(lm1, conf.level = 0.95)
