program ricorsione_inverti;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type vettore=array[1..5]of integer;
var
vettA,vettC:vettore;
i,j:integer;
procedure invert(var vettC:vettore;vettA:vettore;j,i:integer);
begin
if i=0 then
writeln('Vettore invertito:')
else
begin
vettC[j]:=vettA[i];
invert(vettC,vettA,j+1,i-1);
end;
end;

begin
for i:=1 to 5 do
begin
writeln('Inserisci l'' elemento ',i,' del vettore');
readln(vettA[i]);
end;
invert(vettC,vettA,1,5);
for j:=1 to 5 do
begin
writeln(' ',vettC[j]);
end;
readln;
end.
