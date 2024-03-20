import (
	pq "github.com/emirpasic/gods/queues/priorityqueue"
)

type Element struct {
	barcode int16
	count   int16
}

func byReverseCount(a, b interface{}) int {
	return int(b.(Element).count - a.(Element).count)
}

func rearrangeBarcodes(barcodes []int) []int {
	n := len(barcodes)

    // count frequency of barcode occurrences
	freq := make(map[int16]int16)
	for i := 0; i < n; i++ {
		freq[int16(barcodes[i])]++
	}

	// priority queue by frequency
	queue := pq.NewWith(byReverseCount)
	for barcode, count := range freq {
		queue.Enqueue(Element{barcode, count})
	}

	// interleave the barcodes, in order of frequency
	result := make([]int, n)

	prevBarcode := int16(0)
	for i := 0; i < n; i++ {

        // get the most frequent barcode first (ignore error, because problem guarantess an answer!!!)
		e, _ := queue.Dequeue()
        x := e.(Element)

        // check wether it's the same as the previous one
		if x.barcode == prevBarcode {

            // then we get the second most frequent instead
			e, _ := queue.Dequeue()
            y := e.(Element)

            // place the second most frequent barcode in the result
			result[i] = int(y.barcode)
			
            // decrement and place it back if we still have more
            y.count--
            if y.count > 0 {
			    queue.Enqueue(y)
            }

            // advance to place the element we got previously
            i++	
		}		

        // place the most frequent barcode in the result
        result[i] = int(x.barcode)

        // decrement and place it back if we still have more
        x.count--
        if x.count > 0 {
            queue.Enqueue(x)
        }

		prevBarcode = x.barcode
	}
	return result
}