----------------------------------------------------------------------------------
-- Company:         Monish Kumar Bairagi 
-- Project Name:    eightBit_SIPO
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity eightBit_SIPO is
    Port ( D : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           Dout : out  STD_LOGIC_VECTOR (7 downto 0));
end eightBit_SIPO;

architecture Behavioral of eightBit_SIPO is
signal temp : STD_LOGIC_VECTOR (7 downto 0);
begin
process(CLK,CLR)
begin 
	if(CLR = '0') then
		Dout <= "00000000";
		temp <= "00000000";
	elsif(CLK' event and CLK = '1') then
		temp(7) <= D;
		temp(6) <= temp(7);
		temp(5) <= temp(6);
		temp(4) <= temp(5);
		temp(3) <= temp(4);
		temp(2) <= temp(3);
		temp(1) <= temp(2);
		temp(0) <= temp(1);
	end if;
	Dout <= temp;
end process;
end Behavioral;

