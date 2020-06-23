
fun main(args: Array<String>) {
    var (n, k) = readLine()!!.split(" ").map{it.toInt()}
    
    while(k > 0) {
        if(n % 10 == 0) {
            n /= 10
            --k
        } else {
            var temp = minOf(k, n%10)
            n -= temp
            k -= temp
        }
    }

    println(n)
}
