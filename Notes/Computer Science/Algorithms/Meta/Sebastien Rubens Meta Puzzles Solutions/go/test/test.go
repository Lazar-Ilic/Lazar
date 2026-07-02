package test

import (
	"fmt"
	"meta_puzzles/std"
)

type Result interface {
	GetResult() any
}

type predicate_t[T std.Comparable] func(x T, y T) bool

func RunAllTests[Args Result, Ret std.Comparable](name string, args_lists []Args, wrapper func(Args) Ret, params ...predicate_t[Ret]) uint {
	fmt.Printf("\n%s\n", name)
	pred := func(lhs Ret, rhs Ret) bool { return lhs == rhs }
	if len(params) > 0 {
		pred = params[0]
	}
	nb_errors := uint(0)
	for nb, args := range args_lists {
		res := wrapper(args)
		expected := args.GetResult()
		is_same := pred(res, expected.(Ret))
		if is_same {
			fmt.Printf("  test #%v: res=%v CORRECT\n", nb+1, res)
		} else {
			fmt.Printf("  test #%v: res=%v expected=%v ERROR <-----\n", nb+1, res, expected)
			nb_errors += 1
		}
	}
	return nb_errors
}
