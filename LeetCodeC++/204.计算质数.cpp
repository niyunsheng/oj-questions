//Count Primes判断是否为素数的高效方法，这道题用普通方法来判断素数的话必然超限，在别人的博客上看到了一个比较高效的判断素数的方法： 大于等于5的质数一定和6的倍数相邻。例如5和7，11和13,17和19等等；换句话说：不与6的倍数相邻的数一定不是素数，与6的倍数相邻的数不一定是素数。所以我们先排除掉不与6相邻的数，再判断与6的倍数相邻的数是否是素数。
