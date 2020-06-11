----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   Comparator
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Comparator is generic(n: natural :=2);
    Port ( A : in  STD_LOGIC_VECTOR(n-1 downto 0);
           B : in  STD_LOGIC_VECTOR(n-1 downto 0);
           less : out  STD_LOGIC;
           equal : out  STD_LOGIC;
           greater : out  STD_LOGIC);
end Comparator;

architecture Behavioral of Comparator is
begin
process(A,B)
begin
	if(A<B) then
		less <= '1';
		equal <= '0';
		greater <= '0';
	elsif(A=B) then
		less <= '0';
		equal <= '1';
		greater <= '0';
	else
		less <= '0';
		equal <= '0';
		greater <= '1';
	end if;
end process;
end Behavioral;

