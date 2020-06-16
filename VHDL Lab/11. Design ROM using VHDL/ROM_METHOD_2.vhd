----------------------------------------------------------------------------------
-- Engineer: 		Monish Kumar Bairagi
-- Project Name: 	ROM_METHOD_2
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ROM_METHOD_2 is
	port(addr : in STD_LOGIC_VECTOR(2 downto 0);
			M: out STD_LOGIC_VECTOR(7 downto 0));
end ROM_METHOD_2;

architecture Behavioral of ROM_METHOD_2 is
	constant data0: STD_LOGIC_VECTOR (7 downto 0) := "10000101";
	constant data1: STD_LOGIC_VECTOR (7 downto 0) := "11000100";
	constant data2: STD_LOGIC_VECTOR (7 downto 0) := X"E6";
	constant data3: STD_LOGIC_VECTOR (7 downto 0) := X"55";
	constant data4: STD_LOGIC_VECTOR (7 downto 0) := X"67";
	constant data5: STD_LOGIC_VECTOR (7 downto 0) := X"D4";
	constant data6: STD_LOGIC_VECTOR (7 downto 0) := "11110100";
	constant data7: STD_LOGIC_VECTOR (7 downto 0) := "11000110";
	
	type rom_array is array(NATURAL range <>) of STD_LOGIC_VECTOR (7 downto 0);
	constant rom: rom_array := (
		data0, data1, data2, data3,
		data4, data5, data6, data7
	);

begin
	process(addr)
	variable j: integer;
	begin
		j := conv_integer(addr);
		M <= rom(j);
	end process;
end Behavioral;
