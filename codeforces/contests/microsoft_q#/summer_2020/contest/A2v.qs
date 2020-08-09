namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using(q = Qubit[2]) {
            if(M(q[0]) == Zero) {
                X(q[0]);
            }
            if(M(q[1]) == Zero) {
                X(q[1]);
            }
            unitary(q);
            if(M(q[0]) == Zero) {
                Reset(q[0]);
                Reset(q[1]);
                return 2;
            } elif(M(q[1]) == Zero) {
                Reset(q[0]);
                Reset(q[1]);
                return 1;
            } else {
                Reset(q[0]);
                unitary(q);
                let res = M(q[0]);
                Reset(q[0]);
                Reset(q[1]);
                if(res == Zero) {
                    return 0;
                } else {
                    return 3;
                }
            }
        }
    }
}
