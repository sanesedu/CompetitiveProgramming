
fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    var s = readLine()!!
    
    var m = mutableMapOf<String, Int>()

    for(i in 0..(n-2)) {
        if(!m.contains(s.substring(i, i+2))) {
            m[s.substring(i, i+2)] = 1
        } else {
            m[s.substring(i, i+2)] = m[s.substring(i, i+2)]!! + 1
        }
    }
    
    var mx = 0
    var res = ""
    
    for((key, value) in m) {
        if(value > mx) {
            mx = value
            res = key
        }
    }

    println(res)
}
