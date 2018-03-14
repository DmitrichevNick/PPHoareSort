generator 0 1
solver 1 1.ans

generator 1 2
solver 2 2.ans

generator 21474836 3
solver 3 3.ans

for /L %%i in (4,1,50) do (
	generator %%i
	solver %%i %%i.ans
)