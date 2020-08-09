namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit()) {
          //force qubit to be in |0> state
		  Reset(qs);
          //apply the unitary
          unitary(qs);
          //measure the resulting state of the qubit
          let res = M(qs);
          //force qubit to be in |0> state when released
          Reset(qs);
          //if state remains |0> the unitary was the Identity gate
          if(res == Zero) {
              return 0;
		  } else {
              return 1;
		  }
        }
    }
}
