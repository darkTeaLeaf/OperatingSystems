while true;do 
 if ln ex2.txt ex2.txt.close
  then
   sleep 1
  else
   sh ex2.sh
   rm ex2.txt.lock
   break
 fi
done
