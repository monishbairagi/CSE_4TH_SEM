----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   ANDgateBehavioural
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ANDgateBehavioural is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end ANDgateBehavioural;

architecture Behavioral of ANDgateBehavioural is
begin
process(A,B)
begin
	if (A = '1' and 'B' = '1') then
		Y <= '1';
	else
		Y <= '0';
	end if;
end process;
end Behavioral;