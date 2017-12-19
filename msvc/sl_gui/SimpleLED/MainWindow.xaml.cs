using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SimpleLED
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort serial;
        public MainWindow()
        {
            InitializeComponent();
            RefreshPortList();
            previewRect.Fill = Brushes.Black;
            previewLabel.Content = "R: 0" + ", " + "G: 0" + ", " + "B: 0";
        }
        void RefreshPortList()
        {
            string[] ports = SerialPort.GetPortNames();
            comBox.Dispatcher.BeginInvoke(new Action(delegate()
            {
                comBox.Items.Clear();
                for (int i = 0; i < ports.Length; i++)
                {
                    comBox.Items.Add(ports[i]);
                } 
            }));
        }
        private void ColorChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            SolidColorBrush scb = new SolidColorBrush(Color.FromRgb((byte)redSlider.Value, (byte)greenSlider.Value, (byte)blueSlider.Value));
            previewRect.Fill = scb;
            previewLabel.Content = "R: " + Math.Floor(redSlider.Value).ToString() + ", " + "G: " + Math.Floor(greenSlider.Value).ToString() + ", " + "B: " + Math.Floor(blueSlider.Value).ToString();
            if(autosendBox.IsChecked == true)
            {
                sendButton_Click(new object(), new RoutedEventArgs());
            }
        }

        private void sendButton_Click(object sender, RoutedEventArgs e)
        {
            string port = comBox.SelectedItem.ToString().Split(' ')[1];
            serial = new SerialPort(port);
            serial.Open();
            if (serial.IsOpen)
            {
                byte[] data = new byte[] { (byte)redSlider.Value, (byte)greenSlider.Value, (byte)blueSlider.Value };
                serial.Write(data, 0, 3);
                log.Content = "Successfully sended";
            }
            serial.Close();
        }

        private void comBox_MouseDown(object sender, MouseButtonEventArgs e)
        {
            RefreshPortList();
        }
    }
}
