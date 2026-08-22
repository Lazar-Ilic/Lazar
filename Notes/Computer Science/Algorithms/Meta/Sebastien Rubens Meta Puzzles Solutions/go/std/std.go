// meta_puzzles by Sebastien Rubens
//
// Please go to https://github.com/seb-pg/meta_puzzles/README.md
// for more information
//
// To the extent possible under law, the person who associated CC0 with
// meta_puzzles has waived all copyright and related or neighboring rights
// to meta_puzzles.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

package std

type Number interface {
	~uintptr |
		~int | ~int8 | ~int32 | ~int64 |
		~uint | ~uint8 | ~uint32 | ~uint64 |
		~float32 | ~float64
}

type Comparable interface {
	Number | ~string
}

func Less[T Comparable](x, y T) bool {
	return x < y
}

func Greater[T Comparable](x, y T) bool {
	return x > y
}

func Max[T Number](x, y T) T {
	if Greater(x, y) {
		return x
	}
	return y
}

func Min[T Number](x, y T) T {
	if Less(x, y) {
		return x
	}
	return y
}

type predicate_t[T any] func(x T, y T) bool

func _minmax_element[T Comparable](elements []T, pred predicate_t[T]) *T {
	// similar to C++ std::max_element
	last_pos := 0
	last_elt := &elements[0]
	for pos, elt := range elements[1:] {
		if pred(elt, *last_elt) {
			last_pos = pos + 1
			last_elt = &elements[last_pos]
		}
	}
	return &elements[last_pos]
}

func MaxMinElement[T any](elements []T, pred predicate_t[T]) *T {
	// For anything
	last_pos := 0
	last_elt := &elements[0]
	for pos, elt := range elements[1:] {
		if pred(elt, *last_elt) {
			last_pos = pos + 1
			last_elt = &elements[last_pos]
		}
	}
	return &elements[last_pos]
}

func MaxElement[T Comparable](elements []T) *T {
	// similar to C++ std::max_element
	fn := func(lhs, rhs T) bool { return Greater(lhs, rhs) }
	return _minmax_element(elements, fn)
}

func MinElement[T Comparable](elements []T) *T {
	// similar to C++ std::min_element
	fn := func(lhs, rhs T) bool { return Less(lhs, rhs) }
	return _minmax_element(elements, fn)
}

func Accumulate[T Number, R Number](elements []T, init R) R {
	// similar to C++ std::accumulate
	for _, elt := range elements {
		init += R(elt)
	}
	return init
}

func UniquePred[T any](elements []T, pred predicate_t[T]) int {
	// equivalent of std::unique
	if (len(elements) <= 1) {
		return len(elements)
	}
	last_elt := 0
	for _, elt := range elements[1:] {
		if pred(elt, elements[last_elt]) {
			continue
		}
		last_elt += 1
		elements[last_elt] = elt
	}
	return last_elt + 1
}

func Unique[T Comparable](elements []T) int {
	// equivalent of std::unique
	if (len(elements) <= 1) {
		return len(elements)
	}
	fn := func(lhs, rhs T) bool { return lhs == rhs }
	return UniquePred(elements, fn)
}
