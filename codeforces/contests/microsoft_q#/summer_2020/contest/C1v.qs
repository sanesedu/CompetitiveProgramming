namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        using (anc = Qubit()) { 
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, anc);
                let res = MResetZ(anc);
            } 
            until (res == Zero)
            fixup {
                ResetAll(qs);
            }
        }
    }
}
