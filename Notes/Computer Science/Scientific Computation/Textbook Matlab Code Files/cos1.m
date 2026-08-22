%Program 3.3+ Building a cos calculator key, attempt #1
%Approximates cos curve with degree 3 polynomial
% (Caution: do not use to build bridges,
% at least until we have discussed accuracy.)
%Input: x
%Output: approximation for cos(x)
function y=cos1(x)
%First calculate the interpolating polynomial and
% store coefficients
y=sin1(pi/2-x)