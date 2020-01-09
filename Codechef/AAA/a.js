var t;
t=readline();
while (t--){
    var ans=0; var c=0,str,n;
    n=readline();
    str=readline();
    for (var i=n-1; i>-1; i--){
         if (str[i]=='P')
         c++;
         else {if (c>ans)
         ans=c;
         c=0;
         }
        }
        print (ans);
    }