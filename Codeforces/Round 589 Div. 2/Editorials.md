Create a matrix ex: a[r+2][c+2] to hold cell information.->[2 extra index for 1 based indexing + no need to check overflow]

Cell information:
-1 = Free (can be White or Black)
 0 = Reserved (Must be empty and immutable)
 1 = Occupied (Black cell)
[To make r and c valid, reserved cell never be changed]

Logic:
1. Initialize all cell as free (-1). `memset(a, -1, sizeof(a[0][0]) * (r + 2) * (c + 2));`
2. Take input each row (1 to h) value as "d" and do the following:
    - If d==0, then 1st cell (for 1 base indexing, cell d+1=1 is the 1st cell) must be reserved (0) otherwise cell d+1 reserved.-> cell d+1 reserved because if d+1 cell changed to black then r will be invalid. `a[i][d + 1] = 0;`
    - if d>0 then make all (1 to d) cell occupied (1) 
3. Take input each collum (1 to w) value as "d" and do the following:(same as logic 2, just extra need you to check reserved cell is occupied or not before new cell reserved or occupied)
    - Check required reserved cell is occupied or not. if occupied then it's impossible to make a grid to satisfy such r, c values, so return 0 with "0" output.
    - make cell d+1 reserved.
    - if d>0 then make all (1 to d) cell occupied (1) BUT befor made occupied check it previously reserved or not. If reserved then return 0 with "0" output.
4. Count how many free (-1) cell do you have for combinations. If free cell is zero then ans = 1(initialized) otherwise ans = 2^free_cell. 