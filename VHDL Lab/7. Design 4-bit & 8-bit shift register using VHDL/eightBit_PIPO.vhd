----------------------------------------------------------------------------------
-- Engineer:        Monish Kumar Bairagi
-- Project Name:    eightBit_PIPO 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity eightBit_PIPO is
    Port ( CLK : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           Din : in  STD_LOGIC_VECTOR (7 downto 0);
           Dout : out  STD_LOGIC_VECTOR (7 downto 0));
end eightBit_PIPO;

architecture Behavioral of eightBit_PIPO is
begin
	process(CLK,CLR)
		begin
			if(CLR = '0')then 
				Dout <= "00000000";
			elsif(CLK' event and CLK = '1')then 
				Dout <= Din;
			end if;
	end process;
end Behavioral;