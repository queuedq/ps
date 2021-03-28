#!/bin/bash
for i in {0..9}
do
  echo "Generating ${i}th test case..."
  echo -e "200000\n$i" | python gen.py > $i.in
  ./main < $i.in > $i.out
done
echo "Done!"
