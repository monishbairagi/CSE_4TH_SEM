----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   ORgateDataFlow
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ORgateDataFlow is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end ORgateDataFlow;

architecture Behavioral of ORgateDataFlow is
begin
process(A,B)
begin
	if (A = '0' and 'B' = '0') then
		Y <= '0';
	else
		Y <= '1';
	end if;
end process;
end Behavioral;