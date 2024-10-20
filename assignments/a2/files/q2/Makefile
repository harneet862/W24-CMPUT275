Test1:
	i=1
	myTemp1=$(mktemp)
	myTemp2=$(mktemp)
	./rpn < test1.in > ${myTemp1}
	./rpn_sample < test1.in > ${myTemp2}
	diff "${myTemp1}" "${myTemp2}" 
	if [[ $? -eq 0 ]]; then
	    echo "Test ${i} passed"
	else
	    echo "Test ${i} failed"
	rm "${myTemp1}" "${myTemp2}"