----------------------------------------------------------------------------------
-- Engineer:  		Monish Kumar Bairagi
-- Project Name: 	ROM_METHOD_1
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ROM_METHOD_1 is
port(	Clock : in STD_LOGIC;
		Reset : in STD_LOGIC;
		Enable : in STD_LOGIC;
		Read1 : in STD_LOGIC;
		Address : in STD_LOGIC_VECTOR(4 downto 0);
		Data_out : out STD_LOGIC_VECTOR(7 downto 0)
		);
end ROM_METHOD_1;

architecture Behavioral of ROM_METHOD_1 is 
	type ROM_Array is array (0 to 31) 
		of STD_LOGIC_VECTOR(7 downto 0);
	constant Content: ROM_METHOD_1_Array := (
		0 => "00000001",
		1 => "00000010",
		2 => "00000011",
		3 => "00000100",
		4 => "00000101",
		5 => "00000110",
		6 => "00000111",
		7 => "00001000",
		8 => "00001001",
		9 => "00001010",
		10 => "00001011",
		11 => "00001100",
		12 => "00001101",
		13 => "00001110",
		14 => "00001111",
		OTHERS => "11111111"
	);
	begin
		process(Clock, Reset, Read1, Address)
		begin
			if(Reset = '1') then
				Data_out <= "ZZZZZZZZ";
			elsif(Clock'event and Clock = '1') then
				if Enable = '1' then
					if(Read1 = '1') then
						Data_out <= Content(conv_integer(Address));
					else
						Data_out <= "ZZZZZZZZ";
					end if;
				end if;
			end if;
		end process;
end Behavioral;
