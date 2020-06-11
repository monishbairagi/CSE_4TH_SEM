----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   SRAM
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity SRAM is
generic(width: integer:=4;
	depth: integer:=4;
	addr: integer:=2);
port(	Clock: in std_logic;
	Enable: in std_logic;
	Read1: in std_logic;
	Write1: in std_logic;
	Read_Addr: in std_logic_vector(addr-1 downto 0);
	Write_Addr: in std_logic_vector(addr-1 downto 0);
	Data_in: in std_logic_vector(width-1 downto 0);
	DAta_out: out std_logic_vector(width-1 downto 0));
end SRAM;

architecture Behavioral of SRAM is
type ram_type is array (0 to depth-1) of std_logic_vector(width-1 downto 0);
signal tmp_ram: ram_type;
begin
	process(Clock, Read1)
	begin
		if(Clock'event and Clock='1') then
			if Enable='1' then
				if Read1='1' then
					Data_out <= tmp_ram(conv_integer(Read_Addr));
				else
					Data_out <= (Data_out'range => 'Z');
				end if;
			end if;
		end if;
	end process;
	
	process(Clock, Write1)
	begin
		if(Clock'event and Clock='1') then
			if Enable='1' then
				if Write1='1' then
					tmp_ram(conv_integer(Write_Addr)) <= Data_in;
				end if;
			end if;
		end if;
	end process;
end Behavioral;