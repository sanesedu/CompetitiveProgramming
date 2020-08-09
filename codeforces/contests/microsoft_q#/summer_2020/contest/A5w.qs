﻿namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
 
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using(qs = Qubit()) {
            let iters = Round(PI()/theta);
            for(index in 0 .. iters - 1) {
                unitary(qs);
            }
            let res = M(qs);
            Reset(qs);
            if(res == Zero) {
                return 0;
            } else {
                return 1;
            }
	    }
    }
}
