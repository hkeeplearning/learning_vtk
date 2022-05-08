#include <iostream>

#include <vtkSmartPointer.h>
// �̳�vtkPolyDataAlgorithm����������������VTKPolyData������һ����������Ⱦ����ԭ���Բ��
#include <vtkCylinderSource.h>
// �̳�vtkMapper, ������ȾvtkPolyData���͵����ݣ������ǽ����������ת��Ϊ����ͼԪ���㣬�ߣ�����Σ�������Ⱦ
#include <vtkPolyDataMapper.h>
//
// �̳�vtkProp����Ⱦ�����еĿ��ӻ����ͨ��vtkProp���ฺ��������������vtkMapper��������ݺ���Ⱦ��Ϣ����vtkProperty�����������ɫ����͸���ȵȲ�������
// ���⣬vtkActor�л����������������vtkTexture������������ͼ
// 
// VTK�����˴���vtkProp�����࣬��vtkImageActor��vtkPieChartActor��
// ������һЩProp�ڲ������˿�����ʾ�Ĳ����ʹ���Ⱦ���ݵ���������˲���Ҫ�����Property��Mapper��
//
#include <vtkActor.h>
//
// �̳�VTKViewPort
// �������������Ⱦ���̣���ɳ����Ķ������Prop��Camera��Light��
//
#include <vtkRenderer.h>
// vtkRenderWindow ������ϵͳ��VTK��Ⱦ�������ӵ�һ��
// 
// RenderWindow ����һ���û�����Ĵ��ڣ�������Է��ö��renderer��������ʾͼ��
// 
// vtkRenderWindow�а�����vtkRenderer���ϣ���Ⱦ�����ȡ�
//
#include <vtkRenderWindow.h>
//
// �ṩƽ̨��������Ӧ��꣬���̺�ʼ���¼��Ľ������ơ�
// ����Ҫ������������������Ⱦ���ڣ���Ϊ��Ϣ��ͨ����Ⱦ���ڲ��񵽵ġ�
//
#include <vtkRenderWindowInteractor.h>
//
// ��������ʽ��һ��
//
#include <vtkInteractorStyleTrackballCamera.h>


int main() {
  auto cylinder = vtkSmartPointer<vtkCylinderSource>::New();
  cylinder->SetHeight(3.0); //Question �������ø߶ȺͰ뾶����ֵ�ĵ�λ��ʲô��
  cylinder->SetRadius(1.0);
  cylinder->SetResolution(10);

  auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(cylinder->GetOutputPort());

  auto actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(0.1, 0.2, 0.4);

  auto render_win = vtkSmartPointer<vtkRenderWindow>::New();
  render_win->AddRenderer(renderer);
  render_win->SetSize(420, 128); // ��λ������

  auto render_win_interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  render_win_interactor->SetRenderWindow(render_win);

  auto istyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
  render_win_interactor->SetInteractorStyle(istyle);

  render_win_interactor->Initialize(); // ��ʼ����Ϊ�������¼���׼��
  render_win_interactor->Start(); // �ȴ��û������¼��ķ���

  return 0;
}