----------------------------------------------------------------------------------
-- Engineer: 	   Monish Kunar Bairagi
-- Project Name:   T_ff
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity T_ff is
    Port ( t : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           set : in  STD_LOGIC;
           q : out  STD_LOGIC;
           qb : out  STD_LOGIC);
end T_ff;

architecture Behavioral of T_ff is

begin
process(t,clk,rst,set)
variable tmp: std_logic;
begin
	if(rst = '1' and set = '1') then
		tmp:='X';
	elsif(rst = '1' and set = '0') then
		tmp:='0';
	elsif(rst = '0' and set = '1') then
		tmp:='1';
	else
		if(rising_edge(clk)) then
			if(t = '0') then
				tmp:=tmp;
			elsif (t = '1') then
				tmp:=not tmp;
			end if;
		end if;
	end if;
	q <= tmp;
	qb <= not tmp;
end process;
end Behavioral;

