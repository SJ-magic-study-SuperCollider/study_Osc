
~host = NetAddr("localhost", 12345); // local hostのport = 12345にsend
~host = NetAddr("localhost", NetAddr.langPort); // sclang自身に送る
~host.sendMsg("/OSC_test", 123.123, 456.456);


~oscfrom = NetAddr("localhost", nil); // oF側のsend元portは、わからないので、nil

~r1 = OSCresponder(
	~oscfrom, // or nill...means from any IP
	// ~host,
	"/OSC_test",
	{
		arg time, responder, msg, address;
		[time, msg, address].postln;
		msg[0].postln;
		msg[1].postln;
		msg[2].postln;
	}
).add;


~r1.remove;



