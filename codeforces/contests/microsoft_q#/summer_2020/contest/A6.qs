namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(qs = Qubit()) {
            Reset(qs);
            H(qs);
            unitary(qs);
            H(qs);
            if(M(qs) == Zero) {
                //it's either I or X
                X(qs);
                let res = M(qs);
                if(res)
            } else {
                //it's either Y or Z
            }
        }
    }
}
