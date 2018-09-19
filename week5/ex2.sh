i=5000
while [ $i -gt 0 ]
do
a=`tail -n 1 ex2.txt`
a=$((a + 1))
echo "$a" >> ex2.txt
i=$((i - 1))
done

