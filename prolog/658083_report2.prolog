perm([],[]).
perm(X,[Y|Z]) :- select(Y,X,W),perm(W,Z).

palindrome(List) :- reverse(List,List).

/*
実行結果 perm
?- perm([1,2,3,4],[3,1,4,2]).
true .

?- perm([1,2,3,4],[5,1,4,2]).
false.

?- perm([1,2,3],Y).          
Y = [1, 2, 3] ;
Y = [1, 3, 2] ;
Y = [2, 1, 3] ;
Y = [2, 3, 1] ;
Y = [3, 1, 2] ;
Y = [3, 2, 1] ;
false.

実行結果 palindrome
?- palindrome([た,け,や,ぶ,や,け,た]).
true.

?- palindrome([か,ば,の|L]).
L = [ば, か] 

*/
