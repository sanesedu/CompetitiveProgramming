namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using(qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary(qs[0..0], (PI(), qs[1]));
            return MResetX(qs[0]) == Zero ? 0 | 1;
        }
    }
}
