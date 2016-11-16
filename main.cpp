#include <iostream>
#define NUM_DATA 5


class LinearHypothesis
{
public:

	float a0, b0, a1, b1;


	LinearHypothesis()
		: a0(0.0f), b0(0.0f), a1(0.0f), b1(0.0f)
	{}


	float neuron1(const float& x_input)
	{
		return a0 * x_input + b0;
	}


	float neuron2(const float& x_input)

	{
		return a1 * x_input + b1;
	}

};


int main()
{


	const float x_data[NUM_DATA] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	const float y_data[NUM_DATA] = { 4.0, 5.0, 6.0, 7.0, 8.0 };

	LinearHypothesis lh;

	const float lr = 0.01; // learning rate

	for (int tr = 0; tr < 10000; tr++)
		for (int i = 0; i < 5; i++)
		{
			// x_data => [ neuron 1 ] =>  output_of_neuron1

			const float ne1_output = lh.neuron1(x_data[i]);
			const float error0 = y_data[i] - ne1_output;

			const double sqr_error0 = 0.5 * error0 * error0;


			const double dse_da0 = error0 * (-x_data[i]);
			const double dse_db0 = error0 * (-1);

			lh.a0 -= dse_da0 * lr;
			lh.b0 -= dse_db0 * lr;

			// output_of_neuron1 => [ neuron 2 ] =>  output_of_neuron2

			const float ne2_output = lh.neuron2(ne1_output);
			const float error1 = y_data[i] - ne2_output;

			const double sqr_error1 = 0.5 * error1 * error1;


			const double dse_da1 = error1 * (-ne2_output);
			const double dse_db1 = error1 * (-1);

			lh.a1 -= dse_da1 * lr;
			lh.b1 -= dse_db1 * lr;


			std::cout << y_data[i] << " " << ne2_output << std::endl;
		}

	return 0;
}