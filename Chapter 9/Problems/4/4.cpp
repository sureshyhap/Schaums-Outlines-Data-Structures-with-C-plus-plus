/*
  X = {a, b, c}
  Y = {e, f, g}

X < Y -> X = {a} -> X < Y -> a
         Y = {c} -> X > Y -> c
	         -> X == Y -> b

X == Y -> d

X >  Y -> X = {e} -> X < Y -> e
          Y = {g} -> X > Y -> g
                  -> X == Y -> f
 */
