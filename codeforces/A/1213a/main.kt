
fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var arr = readLine()!!.split(" ").map{it.toInt()}
    var even = 0

    for(i in arr.indices) {
        if(arr[i] % 2 == 0) ++even
    }

    println(minOf(even, n - even));
}
