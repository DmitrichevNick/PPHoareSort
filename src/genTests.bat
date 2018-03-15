md tests
for /L %%i in (0,1,15) do (	
	generator %%i %%i
	solver %%i %%i.ans
	move %%i tests/%%i
	move %%i.ans tests/%%i.ans
)
