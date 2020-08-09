namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit()) {
            Reset(qs);
            unitary(qs);
            Z(qs);
            unitary(qs);
            let res = M(qs);
            Reset(qs);
            if(res == Zero) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}
