----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   XORgateBehavioral
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity XORgateBehavioral is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end XORgateBehavioral;

architecture Behavioral of XORgateBehavioral is
begin
process(A,B)
begin
	if (A = '0' and 'B' = '0' and A = '1' and 'B' = '1') then
		Y <= '0';
	else
		Y <= '1';
end if;
end process;
end Behavioral;