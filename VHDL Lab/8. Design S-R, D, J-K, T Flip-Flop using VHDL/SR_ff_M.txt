----------------------------------------------------------------------------------
-- Engineer: 	   Monish Kunar Bairagi
-- Project Name:   SR_ff 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SR_ff is
    Port ( s : in  STD_LOGIC;
           r : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           set : in  STD_LOGIC;
           q : out  STD_LOGIC;
           qb : out  STD_LOGIC);
end SR_ff;

architecture Behavioral of SR_ff is
begin
process(s,r,clk,rst,set)
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
			if(s /= r) then
				tmp:=s;
			elsif(s='0' and r='0') then
				tmp:= tmp;
			elsif(s='1' and r='1') then
				tmp:='X';
			end if;
		end if;
	end if;
	q <= tmp;
	qb <= not tmp;
end process;
end Behavioral;
