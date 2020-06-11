----------------------------------------------------------------------------------
-- Engineer:        Monish Kumar Bairagi
-- Project Name:    fourBit_SIPO
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity fourBit_SIPO is
    Port ( D : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           Dout : out  STD_LOGIC_VECTOR (3 downto 0));
end fourBit_SIPO;

architecture Behavioral of fourBit_SIPO is
signal temp : STD_LOGIC_VECTOR (3 downto 0);
begin
process(CLK,CLR)
begin 
	if(CLR = '0') then
		Dout <= "0000";
		temp <= "0000";
	elsif(CLK' event and CLK = '1') then
		temp(3) <= D;
		temp(2) <= temp(3);
		temp(1) <= temp(2);
		temp(0) <= temp(1);
	end if;
	Dout <= temp;
end process;
end Behavioral;