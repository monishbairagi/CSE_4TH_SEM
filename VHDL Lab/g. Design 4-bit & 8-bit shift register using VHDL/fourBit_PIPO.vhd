----------------------------------------------------------------------------------
-- Engineer:        Monish Kumar Bairagi
-- Project Name:    fourBit_PIPO
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity fourBit_PIPO is
    Port ( CLK : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           Din : in  STD_LOGIC_VECTOR (3 downto 0);
           Dout : out  STD_LOGIC_VECTOR (3 downto 0));
end fourBit_PIPO;

architecture Behavioral of fourBit_PIPO is
begin
	process(CLK,CLR)
		begin
			if(CLR = '0')then 
				Dout <= "0000";
			elsif(CLK' event and CLK = '1')then 
				Dout <= Din;
			end if;
	end process;
end Behavioral;