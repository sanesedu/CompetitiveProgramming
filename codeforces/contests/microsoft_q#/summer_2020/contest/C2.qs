namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let N = Length(qs);
        for(i in 0 .. N-2) {
            H(qs[i]);
        }
        // for odd numbers, flip the last bit to 1
        if(parity == 1) {
            X(qs[N-1]);
        }
    }
}

