"use strict"

var quicksort = module.exports = function(array,comparator) {

	var get_pivot = function(left,right) {
		return Math.floor( (right-left) / 2 + left );
	}

	var swap = function(a,b) {
		var tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}

	var partition = function(left, right) {
		var pivot = get_pivot(left, right);
		var pivot_value = array[pivot];
		var store = left;
		swap(pivot, right)
		for (var i = left; i < right; i++) {
			if (!comparator(array[i], pivot_value)) {
				swap(i, store);
				store++;
			}
		}
		swap(store, right);
		return store;
	}

	var qs = function(left, right) {
		if (left >= right) return;
		var part = partition(left, right);
		qs(left, part-1);
		qs(part+1,right); 
	}
	qs(0, array.length-1);
	return array;
}

if (module.parent !== undefined) {
	var comp = function(a,b){return a >= b;};
	var test_array = [];
	for (var i = 0; i < 1000; i++) test_array.push(Math.round(Math.random()*100));
	quicksort(test_array,comp)
	var prev = test_array[0];
	for (var i = 1; i < 1000; i++) {
		if (!comp(test_array[i], prev)) { console.log("FAIL"); return ;}
		prev = test_array[i];
	}
}