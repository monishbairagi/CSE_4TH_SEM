----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   NORgateBehavioral
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity NORgateBehavioral is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end NORgateBehavioral;

architecture Behavioral of NORgateBehavioral is
begin
process(A,B)
begin
	if (A = '0' and 'B' = '0') then
		Y <= '1';
	else
		Y <= '0';
	end if;
end process;
end Behavioral;