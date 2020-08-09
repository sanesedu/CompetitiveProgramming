namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
			//CNOT: flips target (second qubit) if control (first qubit) is |1>
            //IxX: maintains first qubit, flips second qubit

            //force qubits to be in |0> state
		    Reset(qs[0]);
            Reset(qs[1]);

            //applies unitary
            unitary(qs);

            //measure the resulting states of the qubits
            let control = M(qs[0]);
            let target = M(qs[1]);

            //force qubits to be in |0> state when released
            Reset(qs[0]);
            Reset(qs[1]);

            //if target's state flips to |1> the unitary was IxX, as CNOT would have had no effect (control = |0>)
            if(target == One) {
                return 0;
		    } else {
                return 1;
		    }
        }
    }
}
