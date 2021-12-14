#!/bin/sh
echo \\nThis little shell script allows us to easily "test" computorv1
echo \\nType "in" power of 2:
read p2
echo \\nType "in" power of 1:
read p1
echo \\nType "in" power of 0:
read p0
exec ./computorv1 $p2"*X^2"$p1"X^1"$p0"*X^0"