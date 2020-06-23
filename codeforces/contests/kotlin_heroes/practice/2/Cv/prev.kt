
fun main(args: Array<String>) {
    var (n, k) = readLine()!!.split(" ").map{it.toInt()}
    var arr: LongArray = readLine()!!.split(" ").map{it.toLong()}.toLongArray()

    arr.sort()
    
    if(k == 0) {        
        if(arr[0] != 1L) {
            println(1)
        } else {
            println(-1)
        }       
    } else if(k < n && arr[k] == arr[k-1]) {
        println(-1)
    } else {
        println(arr[k-1])
    }
}
