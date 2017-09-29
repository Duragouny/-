program p3;
var a,f:real;
begin
write ('a=');readln(a);
if(a<-1) then
f:=sqr(a)
else if (a>=1) and (a<=2) then
f:=sqr(a)
else
f:=4;
writeln('f=',f:5:2);
readln;
end.